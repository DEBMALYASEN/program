#include<bits/stdc++.h>
using namespace std;
int lcs(string a ,string b)
{
    int dp[100][100];
    int n=a.size();
    int m=b.size();
        for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

return dp[n][m];
}

int main()
{
    string a,b;
    cin>>a>>b;

    cout<<lcs(a,b);
}
