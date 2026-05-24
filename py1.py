
import json
import hashlib
import secrets

p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F
a = 0
b = 7
Gx = 0x79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798
Gy = 0x483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8
n = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141

G = (Gx, Gy)
INF = None

def mod_inv(x: int, m: int) -> int:
    x %= m
    if x == 0:
        raise ZeroDivisionError("inverse of 0")
    return pow(x, -1, m)

def is_on_curve(P):
    if P is None:
        return True
    x, y = P
    return (y*y - (x*x*x + a*x + b)) % p == 0

def point_add(P, Q):
    if P is None:
        return Q
    if Q is None:
        return P

    x1, y1 = P
    x2, y2 = Q

    if x1 == x2 and (y1 + y2) % p == 0:
        return None

    if P == Q:
        lam = (3 * x1 * x1 + a) * mod_inv(2 * y1, p) % p
    else:
        lam = (y2 - y1) * mod_inv(x2 - x1, p) % p

    x3 = (lam * lam - x1 - x2) % p
    y3 = (lam * (x1 - x3) - y1) % p
    return (x3, y3)

def scalar_mul(k: int, P):
    if k % n == 0 or P is None:
        return None
    if k < 0:
        return scalar_mul(-k, (P[0], (-P[1]) % p))

    R = None
    addend = P
    while k:
        if k & 1:
            R = point_add(R, addend)
        addend = point_add(addend, addend)
        k >>= 1
    return R

def sha256_int(msg: bytes) -> int:
    return int.from_bytes(hashlib.sha256(msg).digest(), "big") % n

def ecdsa_sign(msg: bytes, d: int, k: int):
    z = sha256_int(msg)
    R = scalar_mul(k, G)
    r = R[0] % n
    if r == 0:
        raise ValueError("r=0, choose different k")
    s = (mod_inv(k, n) * (z + r * d)) % n
    if s == 0:
        raise ValueError("s=0, choose different k")
    return (r, s)

def kdf_from_x(x: int) -> bytes:
    return hashlib.sha256(x.to_bytes(32, "big")).digest()

def xor_stream(data: bytes, key: bytes) -> bytes:
    out = bytearray()
    ctr = 0
    while len(out) < len(data):
        block = hashlib.sha256(key + ctr.to_bytes(4, "big")).digest()
        out.extend(block)
        ctr += 1
    return bytes(a ^ b for a, b in zip(data, out[:len(data)]))

def main():
    flag = open("flag.txt").read().strip().encode()

    d = secrets.randbelow(n - 1) + 1
    Q = scalar_mul(d, G)
    assert is_on_curve(Q)

    k = secrets.randbelow(n - 1) + 1

    m1 = b"alice->bob : 10"
    m2 = b"alice->bob : 20"

    r1, s1 = ecdsa_sign(m1, d, k)
    r2, s2 = ecdsa_sign(m2, d, k)
    assert r1 == r2

    R = scalar_mul(k, G)
    assert is_on_curve(R)

    S = scalar_mul(d, R)
    key = kdf_from_x(S[0])

    ct = xor_stream(flag, key)

    chal = {
        "curve": "secp256k1",
        "hash": "SHA-256",
        "enc": "XOR(SHA256(key||counter))",
        "pubkey_Q": {"x": hex(Q[0]), "y": hex(Q[1])},
        "ephemeral_R": {"x": hex(R[0]), "y": hex(R[1])},
        "msg1": m1.decode(),
        "sig1": {"r": hex(r1), "s": hex(s1)},
        "msg2": m2.decode(),
        "sig2": {"r": hex(r2), "s": hex(s2)},
        "ciphertext": ct.hex(),
    }

    out_file = "public.json"
    with open(out_file, "w", encoding="utf-8") as f:
        json.dump(chal, f, indent=2, ensure_ascii=False)

    print(f"[+] Wrote challenge to {out_file}")

if __name__ == "__main__":
    main()
