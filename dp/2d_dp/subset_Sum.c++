#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int a[] ,int n,int sum)
{
    bool dp[100][100]={false};


        for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0 || j==a[i])
            dp[i][j]=1;
            else if(j<a[i])
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j-a[i]];
        }
    }
/*    for(int i=0;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            cout<<dp[i][j]<<" ";
            cout<<"\n";
        }*/
        return dp[n-1][sum];

}

int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    int sum;
    cin>>sum;

    cout<<subsetsum(a,n,sum);
}
