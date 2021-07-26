#include<bits/stdc++.h>
using namespace std;


void search(vector<int>a, int low, int high)
{


    if (low > high)
        return;

    if (low == high)
    {
        cout << "The required element is " << a[low];
        return;
    }

    int mid = (low + high) / 2;

    if (mid % 2 == 0)
    {
        if (a[mid] == a[mid + 1])
            search(a, mid + 2, high);
        else
            search(a, low, mid);
    }

    else
    {
        if (a[mid] == a[mid - 1])
            search(a, mid + 1, high);
        else
            search(a, low, mid - 1);
    }
}

int main()
{
    vector<int>a= { 1, 1, 2, 4, 4, 5, 5, 6, 6 };

    search(a, 0, a.size() - 1);

    return 0;
}
