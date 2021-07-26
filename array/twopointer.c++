#include<bits/stdc++.h>
using namespace std;

int isPairSum(int A[], int N, int X)
{

    int i = 0;

    int j = N - 1;

    while (i < j)
    {

        if (A[i] + A[j] == X)
            return 1;

        else if (A[i] + A[j] < X)

            i++;

        else 
        j--;
    }
    return 0;
}

int main()
{
    int arr[] = { 3, 5, 9, 2, 8, 10, 11 };

    int val = 17;

    printf("%d", isPairSum(arr, 7, val));

    return 0;
}
