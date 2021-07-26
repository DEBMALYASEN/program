#include <bits/stdc++.h>

using namespace std;

void printPairs(int a[], int n, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int temp = sum - a[i];

        if (s.find(temp) != s.end())
            cout << "Pair with given sum "<< sum << " is (" << a[i] << ","<< temp << ")" << endl;

        s.insert(a[i]);
    }
}



int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);

    printPairs(A, 6, n);

    return 0;
}
