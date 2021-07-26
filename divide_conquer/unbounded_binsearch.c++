
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int low, int high)
{

    if (high < low)
        return -1;

    int mid =(low+high)/2;


    if (f(mid) > 0)
    {
        if (mid == low || f(mid - 1) <= 0)
            return mid;

        return binarySearch(low, mid - 1);
    }

    return binarySearch(mid + 1, high);
}

int exponentialSearch()
{
    int i = 1;
    while (f(i) <= 0)
        i *= 2;
    return binarySearch(i/2, i);
}
int f(int x)
{
    return 3*x - 100;
}

int main(void)
{
    int x = exponentialSearch();
    cout<<x;
    return 0;
}
