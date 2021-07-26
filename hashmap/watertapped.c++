#include <bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{

    int result = 0;

    int left_max = 0, right_max = 0;

    int l= 0, h = n - 1;

    while (l <= h)
     {
        if (arr[l] < arr[h])
         {
            if (arr[l] > left_max)
                left_max = arr[l];
            else
                result += left_max - arr[l];
            l++;
        }
        else //arr[h]>ar[l]
        {
            if (arr[h] > right_max)
                right_max = arr[h];

            else
                result += right_max - arr[h];
            h--;
        }
    }

    return result;
}

int main()
{
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findWater(arr, n);
}
