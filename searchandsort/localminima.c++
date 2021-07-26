#include <bits/stdc++.h>
using namespace std;

int findlocalmin(vector<int>a)
{
    int l=0;
    int h=a.size()-1;
while(l<h)
{
    int mid = l + (h - l) / 2;

    if ((mid == 0 || a[mid - 1] >a[mid]) && (mid == a.size() - 1 || a[mid + 1] > a[mid]))
        return a[mid];

    else if (mid > 0 && a[mid - 1] < a[mid])
        h=mid - 1;

    else
        l= mid + 1;
}
}



int main()
{
    vector<int>a = { 1, 3, 1, 4, 1, 0 };

    cout<< findlocalmin(a);
    return 0;
}
