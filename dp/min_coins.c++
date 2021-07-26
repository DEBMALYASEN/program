#include<bits/stdc++.h>
using namespace std;
int min_coins(int n , int coins[],int t)
{   int i,j;
    int dp[1000]={0};
    for(i=1;i<=n;i++)
    {
        dp[i]=INT_MAX;

        for(j=0;j<t;j++)
        {   if(i-coins[j]>=0)
            dp[i]=min(dp[i-coins[j]]+1,dp[i]);//find min of all i-conis[j]
        }
    }
return   dp[n];
}
int main()
{
    int n;
    cin>>n;
    int d[10]={1,2,5,10,20,50,100,200,500,2000};
    cout<<min_coins(n,d,10);
}
