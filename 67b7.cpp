#include <iostream>
#include <string>
using namespace std;

int main() {
    string W;
    getline(cin, W);

    bool daInChu = false;   // ð? in k? t? ch? chýa
    bool truocLaSpace = false;

    for (int i = 0; i < W.length(); i++) {
        if (W[i] != ' ') {
            cout << W[i];
            daInChu = true;
            truocLaSpace = false;
        } else {
            if (daInChu && !truocLaSpace) {
                cout << ' ';
                truocLaSpace = true;
            }
        }
    }

    return 0;
}

