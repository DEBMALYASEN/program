#include <bits/stdc++.h>
using namespace std;

void fixArray(int arr[], int n)
{

    for (int i = 0; i < n;)
    {
        if (arr[i] >= 0 && arr[i] != i)
            swap(arr[i],arr[arr[i]]);
        else
            i++;
    }
}

int main()
{
    int arr[] = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 };

    fixArray(arr, 10);


    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}
