#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;

    //Cau 1
    int check = 0;
    cout << "a. Cac so nguyen to <= n: ";
    for (int i=2;i<=n;i++)
    {
        for (int j=1; j<=i; j++)
            if(i%j==0 && j>1 && j<i)
            {
                check = 1;
                break;
            }
        if(check == 0) cout << i << " ";
        else check = 0;
    }
    cout << endl;

    //Cau 2
    float T = 1.0;
    cout << "b. T= ";
    for (int i = 2; i<=n; i++)
    {
        T += 1.0/i;
    }
    cout << T << endl;

    //Cau 3
    long long P = 1;
    cout << "c. P= ";
    for (int i = 2; i<=n; i++)
    {
        P = P * i;
    }
    cout << P << endl;

    //Cau 4
    float S = 1.0;
    cout << "d. S= ";
    for (int i = 2; i<=n; i++)
    {
        S += pow(-1.0,i-1)/i;
    }
    cout << S << endl;

    //Cau 5
    double Q = 1.0;
    long long tich = 1;
    cout << "d. Q= ";
    for (int i = 2; i<=n; i++)
    {
        tich = 1;
        for (int j=2; j<=i; j++) tich = tich * j;
        Q += pow(-1.0,i-1)/tich;
    }
    cout << Q << endl;

    system("pause");
}