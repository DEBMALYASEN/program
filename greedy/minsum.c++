#include<bits/stdc++.h>
using namespace std;


int minSum(int a[], int n)
{
    sort(a,a+n);

    int num1 = 0;
    int num2 = 0;
    for(int i = 0;i<n;i++)
    {
        if(i%2==0)
            num1 = num1*10+a[i];

        else
        num2 = num2*10+a[i];
    }
    return num2+num1;
}


int main()
{
    int a[] = {5, 3, 0, 7, 4};

    cout<<minSum(a, n)<<endl;
    return 0;
}
