#include<bits/stdc++.h>
using namespace std;
int totalways(int (&a)[100][100],int n)
{
    int dp[101][101];
    int i,j;

   for(i=0;i<n;i++)
   {
    dp[i][0]=1;
    dp[0][i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    int n;
    cin>>n;
    int a[100][100]={0};
    for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    cin>>a[i][j];
}
totalways(a,n);

}
