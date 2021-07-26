#include <bits/stdc++.h>
using namespace std;

int find3Numbers(int a[], int n, int sum)
{
    int l, r;
    int count=0;

    sort(a, a + n);


    for (int i = 0; i < n - 2; i++)
     {

        l = i + 1;
        r = n - 1;
        while (l < r)
        {

             if (a[i] + a[l] + a[r] < sum)
             { count+=r-l;
                l++;
            }
            else
                r--;
        }
    }

    return count;
}
int main()
{
    int a[] = { 1, 0, -2,- 6, 10, 8 };
    int sum = 0;//trip;ets less than 0


    cout<<find3Numbers(a, 6, sum);

    return 0;
}
