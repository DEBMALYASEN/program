#include<bits/stdc++.h>
using namespace std;


int unboundedKnapsack(int W, int n, int val[], int wt[])
{
    int dp[100];

    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);

    return dp[W];
}


int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};


    cout << unboundedKnapsack(W, 3, val, wt);

    return 0;
}
