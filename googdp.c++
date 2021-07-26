#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using  namespace std;
// using namespace __gnu_pbds;

int main()
{
    int t; cin>>t;

    while(t--)
    {
        long long n,m; cin>>n>>m;

        vector<vector<long long>> grid(n,vector<long long>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }

        long long dp[n][m][2];

        for(int i=0;i<n;i++)
        {
            dp[i][m-1][0]=dp[i][m-1][1]=grid[i][m-1];
        }

        for(int c = m-2;c>=0;c--)
        {
            for(int i=0;i<n;i++)
            {
                long long diff=1e18;

                for(int j=0;j<n;j++)
                {
                    long long Min1,Max1;
                    if(grid[i][c] < dp[j][c+1][0])
                    {
                        Min1=grid[i][c];

                    }
                    else Min1=dp[j][c+1][0];

                    if(grid[i][c] > dp[j][c+1][1])
                    {
                        Max1=grid[i][c];

                    }
                    else
                        Max1=dp[j][c+1][1];

                    if(Max1-Min1 < diff)
                    {
                        diff = Max1-Min1;
                        dp[i][c][0]=Min1;
                        dp[i][c][1]=Max1;
                    }
                }
            }
        }
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          cout<<dp[i][j][0]<<" ";

          cout<<endl;
      }


      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          cout<<dp[i][j][1]<<" ";

          cout<<endl;
      }


        long long diff=1e18,Max,Min;
        for(int i=0;i<n;i++)
        {
            if(abs(dp[i][0][0]-dp[i][0][1]) < diff)
                diff=abs(dp[i][0][0]-dp[i][0][1]);
        }

        cout<<diff<<endl;
    }
}
