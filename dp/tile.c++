#include<bits/stdc++.h>
using namespace std;
int tile(int n) // 4*N using 4*1
{
    int dp[1000]={0};
    dp[1]=dp[2]=dp[3]=1;// only horizontal
    dp[4]=2;//vertical and horizontal
    for(int i=5;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-4];

    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<tile(n);
}
