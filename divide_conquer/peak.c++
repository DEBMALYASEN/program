#include <bits/stdc++.h>
using namespace std;

int findPeak(int a[], int l,int h, int n)
{

    int mid = (l+h)/2;

    if ((mid == 0 || a[mid - 1] <= a[mid]) &&  (mid == n - 1 || a[mid + 1] <= a[mid]))
        return a[mid];

    else if (mid > 0 && a[mid - 1] > a[mid])

        return findPeak(a, l, (mid - 1), n);

    else
        return findPeak(a, (mid + 1), h, n);
}


int main()
{
    int a[] = { 1, 3, 20, 4, 1, 0 };
    cout << "Index of a peak point is "<< findPeak(a, 0,5,6);
    return 0;
}
