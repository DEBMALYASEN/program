

#include<bits/stdc++.h>
using namespace std;

bool checkDuplicatesWithinK(int arr[], int n, int k)
{
    unordered_set<int> set;

    for (int i = 0; i < n; i++)
    {
        if (set.find(arr[i]) != set.end())
            return true;

        set.insert(arr[i]);

        if (i >= k)
            set.erase(arr[i-k]);
    }
    return false;
}


int main ()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (checkDuplicatesWithinK(arr, n, 3))
        cout << "Yes";
    else
        cout << "No";
}
