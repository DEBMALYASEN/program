#include<bits/stdc++.h>
using namespace std;//n-1 n/2 n/3
int min_step_to1(int n)
{
    int dp[1000]={0};
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    dp[i]=min(dp[i-1],min(dp[i/2],dp[i/3]))+1;

    return dp[n];

}
int main()
{
    int n;
    cin>>n;
    cout<<min_step_to1(10);
}
