#include<bits/stdc++.h>
using namespace std;
void coinchange(int a[] ,int n,int sum)
{
    int dp[100][100]={false};

 for(int i=0;i<=sum;i++)
 {
     if(i>=a[0])
     dp[0][i]=i;
 }

 for(int i=0;i<n;i++)
      {
          for(int j=0;j<=sum;j++)
          cout<<dp[i][j]<<" ";
          cout<<"\n";
      }

        for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j>=a[i])
                dp[i][j]=min(dp[i-1][j],(1+dp[i][j-a[i]]));


            else
            dp[i][j]=dp[i-1][j];
        }
    }
   for(int i=0;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        //return dp[n-1][sum];

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

    coinchange(a,n,sum);
}
