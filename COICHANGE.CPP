#include<bits/stdc++.h>
using namespace std;
void coindp(int coins[],int cost)
{
    int n =4;
    int dp[n+1][cost+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=cost;i++)
    {
        dp[0][i]=88;
    }

    for(int i=1;i<=n;i++)
           {
               for(int j=1;j<=cost;j++)
               {
                   if(j<coins[i-1])
                   {
                       dp[i][j]=dp[i-1][j];
                   }
                   else
                   {
                   dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                   }
               }
           }


    for (int i = 0; i < n+1; ++i)
    {
        for (int j = 0; j < cost+1; ++j)
        {
            cout<<dp[i][j]<<" ";}

            cout<<"\n";
        }
    }

int main()
{
int cost[4]={1,2,6,8};
int amount =11;
coindp(cost,amount);
}
