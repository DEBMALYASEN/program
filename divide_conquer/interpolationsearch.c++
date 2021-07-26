#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;

    int   mid = low + ((x - arr[low]) * (high - low) / (arr[high] - arr[low]));

    if (x == arr[mid])
        return mid;

    else if (x < arr[mid])
        return interpolationSearch(arr, low, mid - 1, x);

    else
        return interpolationSearch(arr, mid + 1, high, x);

}
int main(void)
{
    int arr[] = {2, 5, 6, 8, 9, 10};
    cout<<interpolationSearch(arr,0, 5, 10);
    return 0;
}
