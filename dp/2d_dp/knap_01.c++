#include<bits/stdc++.h>
using namespace std;
int knap(int w ,int wt[],int val[],int n)
{
    int dp[100][100];
    for(int i=0;i<n;i++)
    dp[i][0]=0;

   for(int i=0;i<=w;i++)
    {
      if(i>=wt[0])
      dp[0][i]=1;
    }
/*    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";*/
    /* val is what we add we deal with  weights only if current weight is less get value from top
    or else decrement the weight and get the value from abovw */
        for(int i=1;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(j<wt[i])
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]);
        }
    }
/*    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        cout<<dp[i][j]<<" ";
        cout<<"\n";
    }*/
    return dp[n-1][w];
}
int main()
{
    int wt[4]={1,3,4,5};
    int val[4]={1,4,5,7};
    cout<<knap(7,wt,val,4);
}
