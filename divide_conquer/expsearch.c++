#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;

    int mid = (low + high)/2;

    if (x == arr[mid])
        return mid;

    else if (x < arr[mid])
        return BinarySearch(arr, low, mid - 1, x);

    else
        return BinarySearch(arr, mid + 1, high, x);

}

int ExponentialSearch(int arr[], int n, int x)
{
    int bound = 1;

    while (bound < n && arr[bound] < x)
        bound *= 2;

    return BinarySearch(arr, bound/2, min(bound, n), x);
}


int main(void)
{
    int arr[] = {2, 5, 6, 8, 9, 10};
    cout<<ExponentialSearch(arr, 6, 10);
    return 0;
}
