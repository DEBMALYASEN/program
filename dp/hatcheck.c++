#include <bits/stdc++.h>
using namespace std;
int derangements(int n)
{
    int dp[1000];

    dp[1] = 0, dp[2] = 1;

    for (int i = 3; i <= n; i++)
        dp[i] = (i - 1) *(dp[i - 1] + dp[i - 2]);

    return dp[n];
}

int main(void)
{

    int n;
    cin>>n;

    cout<<derangements(n);

    return 0;
}
