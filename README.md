#include <iostream>
#include <string>

using namespace std;

class CongNhan {
private:
    string hoTen;
    float heSoLuong;
    int phuCap;

public:

    CongNhan() {
        hoTen = "";
        heSoLuong = 0;
        phuCap = 0;
    }


    CongNhan(string ht, float hsl, int pc) {
        hoTen = ht;
        heSoLuong = hsl;
        phuCap = pc;
    }


    void nhap() {
        cout << "Nhap ho ten: ";
        cin >> hoTen;
        cout << "Nhap he so luong: ";
        cin >> heSoLuong;
        cout << "Nhap phu cap: ";
        cin >> phuCap;
    }


    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "He so luong: " << heSoLuong << endl;
        cout << "Phu cap: " << phuCap << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }


    float tinhLuong() {
        return heSoLuong * 2340 + phuCap;
    }
};

int main() {
    int n;
    cout << "Nhap so luong cong nhan: ";
    cin >> n;

    CongNhan *congNhan = new CongNhan[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cong nhan thu " << i + 1 << endl;
        congNhan[i].nhap();
    }

    cout << "\nThong tin cac cong nhan:\n";
    for (int i = 0; i < n; i++) {
        congNhan[i].xuat();
        cout << "---------------------\n";
    }


    float minLuong = congNhan[0].tinhLuong();
    int indexMin = 0;
    for (int i = 1; i < n; i++) {
        if (congNhan[i].tinhLuong() < minLuong) {
            minLuong = congNhan[i].tinhLuong();
            indexMin = i;
        }
    }

    cout << "\nCong nhan co luong thap nhat la:\n";
    congNhan[indexMin].xuat();

    delete[] congNhan;
    return 0;
}
