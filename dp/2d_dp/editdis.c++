#include<bits/stdc++.h>
using namespace std;
void editdis(string a ,string b)
{
    int dp[100][100]={},i,j;
    int n=a.size();
    int m=b.size();
    for(i=1;i<=n;i++)
    {
        dp[0][i]=i;
    }
    for(i=1;i<=m;i++)
    {
        dp[i][0]=i;
    }

    for(int i=0;i<=m;i++)
           {
               for(int j=0;j<=n;j++)
               cout<<dp[i][j]<<" ";
               cout<<"\n";
           }


        for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1]) 
            dp[i][j]=dp[i-1][j-1];
            else
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;

        }
    }
cout<<endl;
    for(int i=0;i<=m;i++)
           {
               for(int j=0;j<=n;j++)
               cout<<dp[i][j]<<" ";
               cout<<"\n";
           }



//return dp[n][m];
}

int main()
{
    string a,b;
    cin>>a>>b;

    editdis(a,b);
}
