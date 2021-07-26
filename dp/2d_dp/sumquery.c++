#include<bits/stdc++.h>
using namespace std;
int sumquery(int (&a)[100][100],int n)
{
    int dp[101][101];
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+a[i-1][j-1]-dp[i-1][j-1];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
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
sumquery(a,n);

}
