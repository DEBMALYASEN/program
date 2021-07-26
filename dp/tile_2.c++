#include<bits/stdc++.h>
using namespace std;
int tile(int m,int n) // M*N using M*1
{
    int dp[1000]={0};
    int i;

    for(i=1;i<m;i++)
    dp[i]=1;

    dp[m]=2;

    for(int i=m+1;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-m];

    return dp[n];
}
int main()
{
    int  m,n;
    cin>>m>>n;
    cout<<tile(m,n);
}
