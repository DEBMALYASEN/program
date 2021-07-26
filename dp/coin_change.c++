#include<bits/stdc++.h>
using namespace std;
int coin_change(int coins[],int n , int sum)
{
    int dp[1000]={0};
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=coins[i];j<=sum;j++)
        dp[j]+=dp[j-coins[i]];
    }
    return dp[sum];

}
// we can either choose a coin or we will omit
// case 1  choose (sum decreases ,no of coins remains same)
// case 2 dont choose(sum same .no of coin decreases)
int main()
{
    int n;
    int coins[4]={2,5,6,3};
    cin>>n;
    cout<<coin_change(coins,4,n);
}
