#include <bits/stdc++.h>
using namespace std;
void findFrequency(int arr[], int n, unordered_map<int, int> &count)
{
    if (arr[0] == arr[n - 1])
    {
        count[arr[0]] += n;
        return;
    }

    findFrequency(arr, n/2, count);
    findFrequency(arr + n/2,  n/2, count);
}

int main()
{
    int arr[] = { 2, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9 };
    int n = sizeof(arr) / sizeof(int);

    unordered_map<int, int> map;
    findFrequency(arr, n, map);

    for (auto p: map)
        cout << p.first << " occurs " << p.second << " times\n";


    return 0;
}
