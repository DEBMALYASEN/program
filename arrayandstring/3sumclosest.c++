#include <bits/stdc++.h>
using namespace std;

int findclosestsum(int a[], int n, int target)
{
    int l, r;

    if(n<3)
    return 0;
    sort(a, a + n);
    int min=INT_MAX;
    int sum;


    for (int i = 0; i < n - 2; i++)
     {

        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            int diff=abs(a[i]+a[l]+a[r]-target);
            if (diff==0)
            {
              return target;
            }
            else if(diff<min)
            {
                min=diff;
                sum=a[i]+a[l]+a[r];
            }
            else if (a[i] + a[l] + a[r] < target)
                l++;
            else
                r--;
        }
    }

    return sum;
}
int main()
{
    int a[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 1;


    cout<<findclosestsum(a, 6, sum);

    return 0;
}
