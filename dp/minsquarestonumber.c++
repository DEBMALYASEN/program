#include <bits/stdc++.h>
using namespace std;

int findMinSq(int n)
{
    int dp[1000];
    dp[0]=0;
    dp[1]=1;

    for (int i = 2; i <= n; i++)
     {

        for (int j = 1; j*j <= i; j++)
            dp[i] = min(dp[i], 1 + dp[i - j*j]);
      }

    return dp[n];
}

int main(void)
{
     int n;
     cin>>n;
    cout<< findMinSq(n);

    return 0;
}
