#include<bits/stdc++.h>
using namespace std;

int partition(int A[], int n)
{
    int j = 0;
    int pivot = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < pivot)
        {
            swap(A[i], A[j]);
            j++;
        }
    }

    return j;
}

int rearrange(int A[], int size)
{
    int p = partition(A, size);

    for (int n = 0; (p < size && n < p); p++, n += 2) {
        swap(A[n], A[p]);
    }
}

int main()
{
    int A[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
    int n = sizeof(A)/sizeof(A[0]);
 
    rearrange(A, n);

    for (int i = 0; i < n; i++) {
        cout << setw(3) << A[i];
    }

    return 0;
}
