#include<bits/stdc++.h>
using namespace std;
int catalan(int n)
{
    int dp[1000]={0};
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        dp[i]+=dp[j]*dp[i-j-1];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<catalan(10);
}
//no og bst
//no of trees with a given preorders
