#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        cout << "[1] Buoi sang\n";
        cout << "[2] Buoi trua\n";
        cout << "[3] Buoi chieu\n";
        cout << "[4] Buoi toi\n";
        cout << "[5] Ket thuc\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Chao buoi sang";
                break;
            case 2:
                cout << "Den gio nghi trua roi, di an thoi";
                break;
            case 3:
                cout << "Het gio lam viec, ve nha nao";
                break;
            case 4:
                cout << "Chuan bi ngu buoi toi";
                break;
            case 5:
                cout << "Chuc ngu ngon";
                break;
            default:
                break;
        }
        cout << endl;
    } while (choice != 5);

    return 0;
}

