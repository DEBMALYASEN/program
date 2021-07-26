/ C++ program for above implementation
#include <bits/stdc++.h>
using namespace std;

bool checkCount(int arr[], int n, int k)
{
    unordered_map<int, int> hash;

    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    for (auto x : hash)
        if (x.second > 2 * k)
            return false;

    return true;
}


int main()
{
    int arr[] = { 1, 1, 2, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    checkCount(arr, n, k) ? cout << "Yes"
                           : cout << "No";
    return 0;
}
