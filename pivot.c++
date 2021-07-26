#include <bits/stdc++.h>
using namespace std;

int findPivot(int a[], int start, int end)
{

    int pivot = a[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {

        if (a[i] <= pivot)
         {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    swap(a[pIndex], a[end]);
    return pIndex;
}

void SmallestLargest(int a[], int low, int high, int k,
                     int n)
{
    if (low == high)
        return;
    else {
        int pivotIndex = findPivot(a, low, high);

        if (k == pivotIndex) {
            cout << k << " smallest elements are : ";
            for (int i = 0; i < pivotIndex; i++)
                cout << a[i] << "  ";

            cout << endl;

            cout << k << " largest elements are : ";
            for (int i = (n - pivotIndex); i < n; i++)
                cout << a[i] << "  ";
        }

        else if (k < pivotIndex)
            SmallestLargest(a, low, pivotIndex - 1, k, n);

        else if (k > pivotIndex)
            SmallestLargest(a, pivotIndex + 1, high, k, n);
    }
}

// Driver Code
int main()
{
    int a[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
    int n = sizeof(a) / sizeof(a[0]);

    int low = 0;
    int high = n - 1;

    int k = 3;

    SmallestLargest(a, low, high, k, n);

    return 0;
}
