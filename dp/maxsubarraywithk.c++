
#include<bits/stdc++.h>
using namespace std;

int maxSumWithatleastK(int a[], int n, int k)
{

    int maxSum[n];
    maxSum[0] = a[0];

    int curr_max = a[0];

    for (int i = 1; i < n; i++)
    {
        curr_max = max(a[i], curr_max+a[i]);
        maxSum[i] = curr_max;
    }

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += a[i];

    int result = sum;

    for (int i = k; i < n; i++)
    {

        sum = sum + a[i] - a[i-k];

        result = max(result, sum);
 
        result = max(result, sum + maxSum[i-k]);
    }
    return result;
}


int main()
{
    int a[] = {1, 2, 3, -10, -3};
    int k = 4;
    int n = sizeof(a)/sizeof(a[0]);
    cout << maxSumWithatleastK(a, n, k);
    return 0;
}
