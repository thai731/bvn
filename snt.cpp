#include <iostream>
using namespace std;

int ucln(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int N;
    cout << "Nhap so luong phan tu N: ";
    cin >> N;

    int a[N];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    bool isCoPrime = true;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (ucln(a[i], a[j]) != 1) {
                isCoPrime = false;
                break;
            }
        }
        if (!isCoPrime) break;
    }

    if (isCoPrime) {
        cout << "Cac so nguyen to cung nhau tung doi.";
    } else {
        cout << "Cac so khong phai la nguyen to cung nhau tung doi.";
    }

    return 0;
}
