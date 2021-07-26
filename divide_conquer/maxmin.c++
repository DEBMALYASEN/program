#include <bits/stdc++.h>
using namespace std;


void findMinAndMax(int arr[], int low, int high, int &min, int &max)
{


    if (low == high)
    {
        if (max < arr[low])
            max = arr[low];


        if (min > arr[high])
            min = arr[high];


        return;
    }


    if (high - low == 1)
    {
        if (arr[low] < arr[high])
        {
            if (min > arr[low])
                min = arr[low];


            if (max < arr[high])
                max = arr[high];

        }
        else
        {
            if (min > arr[high])
                min = arr[high];


            if (max < arr[low])
                max = arr[low];

        }
        return;
    }

    int mid = (low + high) / 2;

    findMinAndMax(arr, low, mid, min, max);


    findMinAndMax(arr, mid + 1, high, min, max);
}

int main()
{
    int a[] = { 7, 2, 9, 3, 1, 6, 7, 8, 4 };


    int max = INT_MIN, min = INT_MAX;

    findMinAndMax(a, 0, 8, min, max);

    cout << min << endl;
    cout << max;

    return 0;
}
