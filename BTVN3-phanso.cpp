#include<iostream>
#include<cmath>

using namespace std;

class Phanso
{
    int tu,mau;
    public:
        Phanso(int=0,int=1);
        void nhap();
        void xuat();
        Phanso cong(Phanso x);
        Phanso tru(Phanso x);
        Phanso nhan(Phanso x);
        Phanso chia(Phanso x);
        void rutgon();
};

Phanso::Phanso(int a,int b)
{
    tu = a; mau = b;
}

void Phanso::nhap()
{
    cin >> tu >> mau;
}

void Phanso::xuat()
{
    cout << tu << "/" << mau;
}

Phanso Phanso::cong(Phanso x)
{
    Phanso tam;
    if(mau == x.mau)
        tam.tu = tu + x.tu;
    else
    {
        tam.tu = (tu*x.mau) + (x.tu*mau);
        tam.mau = mau*x.mau;
    }
    return tam;
}

Phanso Phanso::tru(Phanso x)
{
    Phanso tam;
    if(mau == x.mau)
        tam.tu = tu - x.tu;
    else
    {
        tam.tu = (tu*x.mau) - (x.tu*mau);
    }
    return tam;
}

Phanso Phanso::nhan(Phanso x)
{
    Phanso tam;
    tam.tu = tu*x.tu;
    tam.mau = mau*x.mau;
    return tam;
}

Phanso Phanso::chia(Phanso x)
{
    Phanso tam;
    tam.tu = tu*x.mau;
    tam.mau = mau*x.tu;
    return tam;
    return tam;
}

void Phanso::rutgon()
{
    switch (tu>=mau)
    {
    case (true):
        if(tu%mau == 0)
        {
            tu = tu/mau;
            mau = 1;
        }
        else
        for (int i = mau-1; i >=1; i--)
        {
            if(tu%i==0 && mau%i==0)
            {
                tu = tu/i;
                mau = mau/i;
                break;
            }
        }
        break;
    
    case (false):
        if(mau%tu == 0)
        {
            mau = mau/tu;
            tu = 1;
        }
        else
        for (int i = tu-1; i >=1; i--)
        {
            if(tu%i==0 && mau%i==0)
            {
                tu = tu/i;
                mau = mau/i;
                break;
            }
        }
        break;
    }
}

int main()
{
    int n;
    Phanso a[100];
    cout << "Hay nhap so luong phan so: ";
    cin >> n;
    cout << endl;
    cout << "Nhap danh sach phan so:" << endl;
    for (int i=0; i<n; i++)
    {
        cout << "Phan so thu " << i << " la:" << endl;
        a[i].nhap();
    }
    cout << "Danh sach phan so da nhap: ";
    for (int i=0; i<n; i++)
    {
        a[i].xuat();
        cout << " ";
    }
    cout << endl;

    Phanso T;
    for (int i=0; i<n; i++)
    {
        T = T.cong(a[i]);
    }
    cout << "Tong cua cac phan so tren la: ";
    T.rutgon();
    T.xuat();
    system("pause");
}