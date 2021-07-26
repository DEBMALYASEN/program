#include<bits/stdc++.h>
using namespace std;
//double the no of cells x
// increase the no of cells  z
//decrease the no of cells  y
//to 1
int mitosis(int n,int x,int y ,int z)
{
    int dp[100]={0};
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        dp[i]=min(dp[i/2]+x,dp[i-1]+y);
        else
        dp[i]=min(dp[(i+1)/2]+x+z,dp[i-1]+y);
    }
return dp[n];
}
int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;

    cout<<mitosis(n,x,y,z)<<" ";
}
