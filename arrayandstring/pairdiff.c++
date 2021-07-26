#include <bits/stdc++.h>
using namespace std;

bool findPair(int a[], int size, int n)
{
    int i = 0;
    int j = 1;

    while (i < size && j < size)
    {
        if (i != j && arr[j] - arr[i] == n)
        {
            cout << "Pair Found: (" << arr[i] <<", " << arr[j] << ")";
            return true;
        }
        else if (arr[j]-arr[i] < n)
            j++;
        else
            i++;
    }

    cout << "No such pair";
    return false;
}


int main()
{
    int arr[] = {1, 8, 30, 40, 100};

    int n = 60;
    findPair(arr, 5, n);
    return 0;
}
