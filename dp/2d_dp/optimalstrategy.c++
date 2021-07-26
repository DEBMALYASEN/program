
#include <bits/stdc++.h>
using namespace std;
int optimalStrategyOfGame(int a[100], int n)
{
    int dp[100][100];


    for (int gap = 0; gap < n; ++gap)
     {
        for (int i = 0, j = gap; j < n; ++i, ++j)
        {

            int x = ((i + 2) <= j)? dp[i + 2][j]: 0;
            int y = ((i + 1) <= (j - 1))? dp[i + 1][j - 1]: 0;
            int z = (i <= (j - 2))? dp[i][j - 2]: 0;

            dp[i][j] = max(a[i] + min(x, y), a[j] + min(y, z));
        }
    }

    return dp[0][n - 1];
}


int main()
{
    int arr1[] = { 8, 15, 3, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
   cout<<optimalStrategyOfGame(arr1, n)<<endl;

    int arr2[] = { 2, 2, 2, 2 };
    n = sizeof(arr2) / sizeof(arr2[0]);
     cout<<optimalStrategyOfGame(arr2, n)<<endl;

    int arr3[] = { 20, 30, 2, 2, 2, 10 };
    n = sizeof(arr3) / sizeof(arr3[0]);
     cout<<optimalStrategyOfGame(arr2, n);

    return 0;
}
