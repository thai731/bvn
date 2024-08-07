#include<iostream>
#include<cmath>

using namespace std;

class Tamgiac
{
    float a,b,c;
    public:
        Tamgiac(int=0,int=0,int=0);
        float chuvi();
        float dientich();
        void nhap();
        void in();
};

Tamgiac::Tamgiac(int a1, int b1, int c1)
{
    int a = a1; int b = b1; int c = c1;
}

float Tamgiac::chuvi()
{
    return a + b + c;
}

float Tamgiac::dientich()
{
    float p = chuvi()/2;
    return sqrt(p*(p*a)*(p*b)*(p*c));
}

void Tamgiac::nhap()
{
    cin >> a >> b >> c;
}

void Tamgiac::in()
{
    cout << "(" << a << "," << b << "," << c << ")";
}

int main()
{
    int n;
    Tamgiac t[100];
    cout << "So tam giac muon nhap:";
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cout << endl << "Nhap cac canh cua tam giac thu " << i+1 << ":";
        t[i].nhap();
    }
    cout << endl;

    int maxchuvi = 0;
    int maxdientich = 0;

    for (int i=0; i<n; i++)
    {
        if(t[maxchuvi].chuvi() < t[i].chuvi())
            maxchuvi = i;
        if(t[maxdientich].dientich() < t[i].dientich())
            maxdientich = i;
    }

    cout << "Tam giac co chu vi lon nhat la tam giac thu " << maxchuvi+1 << " co ba canh la: ";
    t[maxchuvi].in(); cout << endl;
    cout << "Tam giac co dien tich lon nhat la tam giac thu " << maxdientich+1 << " co ba canh la: ";
    t[maxdientich].in(); cout << endl;

    system("pause");
}