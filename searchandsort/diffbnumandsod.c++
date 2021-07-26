#include <bits/stdc++.h>
using namespace std;

int sumOfDigit(int K)
{

    int sod = 0;
    while (K)
    {
        sod += K % 10;
        K /= 10;
    }
    return sod;
}
int totalNumbersWithSpecificDifference(int N, int diff)
{
    int low = 1, high = N;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid - sumOfDigit(mid) < diff)
            low = mid + 1;
        else
            high = mid - 1;
    }


    return (N - high);
}


int main()
{
    int n = 13;
    int diff = 2;

    cout << totalNumbersWithSpecificDifference(n, diff);
    return 0;
}
