#include<bits/stdc++.h>
using namespace std;
int ladder(int n,int k)
{
    int dp[100]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
        if(i-j>=0)

        dp[i]+=dp[i-j];

        }
     }
return dp[n];
}// N steps K max jumps
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cout<<ladder(i,k)<<" ";
}
