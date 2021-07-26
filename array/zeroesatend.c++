#include<bits/stdc++.h>
using namespace std;

int partition(int A[], int n)
{
    int j = 0;
    int pivot = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] != pivot)
        {
            swap(A[i], A[j]);
            j++;
        }
    }

    return j;
}

int main()
{
    int A[] = { 0, -3, 0, 0, -8, -6, 1, 3 };
    int n = sizeof(A)/sizeof(A[0]);

    partition(A, n);

    for (int i = 0; i < n; i++) {
        cout << setw(3) << A[i];
    }

    return 0;
}
