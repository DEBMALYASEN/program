#include <bits/stdc++.h>
using namespace std;

void productArray(int a[], int n)
{

    if (n == 1)
    {
        cout << 0;
        return;
    }

    int i, temp = 1;

    int prod[n];
    for(int i=0;i<n;i++)
    prod[i]=1;


    for (i = 0; i < n; i++) //left part
    {
        prod[i] = temp;
        temp *= a[i];
    }


    temp = 1;

    for (i = n - 1; i >= 0; i--)

   {
        prod[i] *= temp;
        temp *= a[i];
    }

    for (i = 0; i < n; i++)
        cout << prod[i] << " ";

    return;
}

int main()
{
    int a[] = { 10, 3, 5, 6, 2 };

    productArray(a, 5);
}
