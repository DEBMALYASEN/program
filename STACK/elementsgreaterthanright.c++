#include <bits/stdc++.h>
using namespace std;
void find(int arr[], int n)
{
    int max_so_far = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > max_so_far)
        {
            max_so_far = arr[i];
            cout<< arr[i];
        }
    }
}

int main(void)
{
    int arr[] = { 10, 4, 6, 3, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);

    find(arr, n);

    return 0;
}
