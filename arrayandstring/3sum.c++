#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int a[], int n, int sum)
{
    int l, r;


    sort(a, a + n);


    for (int i = 0; i < n - 2; i++)
     {

        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == sum)
            {
                cout<< a[i]<<" " <<a[l]<<" " <<a[r];
                return true;
            }
            else if (a[i] + a[l] + a[r] < sum)
                l++;
            else
                r--;
        }
    }

    return false;
}
int main()
{
    int a[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;


    find3Numbers(a, 6, sum);

    return 0;
}
