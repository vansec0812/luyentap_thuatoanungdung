#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // b? ký t? xu?ng dòng sau khi nh?p N

    string lang, result;
    int minLen = 1e9;

    for (int i = 0; i < N; i++) {
        getline(cin, lang);

        int len = lang.length();
        if (len <= minLen) {
            minLen = len;
            result = lang; // l?y ph?n t? sau cùng n?u b?ng nhau
        }
    }

    cout << result;
    return 0;
}

