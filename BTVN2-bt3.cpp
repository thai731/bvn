#include<iostream>
#include<fstream>

using namespace std;

int kiemtra(ifstream &a)
{
    if (!a.is_open())
    {
        cout << "Khong the mo hoac tim thay file" << endl;
        return 1;
    }
    return 0;
}

void docfile(ifstream &a, int *n, int b[])
{
    a >> *n;
    for (int i = 0; i < *n; ++i)
    {
        a >> b[i];
    }
}

void merge(int a[], int m, int b[], int n, int c[])
{
    int i=0, j=0, k=0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < m) c[k++] = a[i++];
    while (j < n) c[k++] = b[j++];
}

void inketqua(int n, int a[])
{
    cout << "Mang co " << n << " phan tu:" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int output_file(ofstream &a, int n, int b[])
{
    if(!a.is_open())
    {
        return 1;
    }
    a.clear();
    a << n << endl;
    for (int i=0; i<n; i++)
        a << b[i] << " ";
    a.close();
    return 0;
}

int main()
{
    string tenfile1 = "dat131.txt";
    string tenfile2 = "dat132.txt";
    ifstream input1(tenfile1);
    ifstream input2(tenfile2);

    if (kiemtra(input1) == 0 && kiemtra(input2) == 0)
    {
        int m, n;
        int a[100], b[100], c[100];

        docfile(input1, &m, a);
        docfile(input2, &n, b);

        cout << "Mang o file thu nhat:" << endl;
        inketqua(m, a);

        cout << "Mang o file thu hai:" << endl;
        inketqua(n, b);
        
        merge(a,m,b,n,c);
        cout << "Sau khi merge:" << endl;
        inketqua(m+n, c);
        string tenfile3 = "output13.txt";
        ofstream output(tenfile3);

        if(output_file(output,m+n,c)==0)
            cout << "Da in ket qua ra file "<< tenfile3 << endl;
        else
            cout << "Khong the mo hoac tim thay file " << tenfile3 << endl;

        return 0;
    }
}
