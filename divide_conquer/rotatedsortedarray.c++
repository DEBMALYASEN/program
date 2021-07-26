#include <bits/stdc++.h>
using namespace std;
int searchCircularArray(int A[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {

        int mid = (low + high)/2;

        if (x == A[mid])
            return mid;



        if (A[mid] <= A[high])
        {
            if (x > A[mid] && x <= A[high])
                low = mid + 1;

            else
                high = mid - 1;
        }

        else
        {

            if (x >= A[low] && x < A[mid])
                high = mid - 1;
            else
                low = mid + 1;

        }
    }

    return -1;
}

int main()
{
    int A[] = {9, 10, 2, 5, 6, 8};

    int index = searchCircularArray(A, 6, 5);

    if (index != -1)
        cout<<index;

    return 0;
}
