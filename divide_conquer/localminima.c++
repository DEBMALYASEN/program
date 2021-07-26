#include <bits/stdc++.h>
using namespace std;

int findmin(int a[], int l,int h, int n)
{

    int mid = (l+h)/2;

    if ((mid == 0 || a[mid - 1] > a[mid]) &&  (mid == n - 1 || a[mid + 1] > a[mid]))
        return a[mid];

    else if (mid > 0 && a[mid - 1] <a[mid])

        return findmin(a, l, (mid - 1), n);

    else
        return findmin(a, (mid + 1), h, n);
}


int main()
{
    int a[] = { 1, 3, 2, 4, 1, 0 };
    cout << " local min point is "<< findmin(a, 0,5,6);
    return 0;
}
