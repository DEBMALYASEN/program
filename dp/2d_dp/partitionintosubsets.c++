#include<bits/stdc++.h>
using namespace std;
int partitionintosubsets(int n,int k)
{
    if(n==0 || k==0 || n<k)
    return 0;
    int dp[100][100];
    for(int t=1;t<=k;t++)//team
    {
        for(int p=1;p<=n;p++)players
            {
                if(p<t)
                dp[t][p]=0;
                else if(p==t)
                dp[t][p]=1;
                else
                dp[t][p]=t*dp[t][p-1]+dp[t-1][p-1];

            }
    }
    return dp[k][n];
}
int main()

{
    int n,k;
    cin>>n>>k;
    cout<<partitionintosubsets(n,k);
}
