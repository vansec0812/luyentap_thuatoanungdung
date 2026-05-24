#include <iostream>
#include <string>
using namespace std;

int main() {
    string W;
    cout << "Nhap W = ";
    cin >> W;

    int n = W.length();
    string S = W + W + W;

    cout << "Cac xau con la:" << endl;
    for (int i = 0; i < 3 * n; i += 3) {
        cout << S[i] << S[i + 1] << S[i + 2] << endl;
    }

    return 0;
}

