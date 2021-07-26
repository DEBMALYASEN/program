#include<bits/stdc++.h>
using namespace std;



 int minSquares(int x, int y)
{
int dp[x+1][y+1];

    for (int i=0; i<=x; i++)
     {
      for (int j=0; j<=y; j++)
      {
        if (i==0 || j==0)
         {
          dp[i][j] = 0;
          continue;
        }
        if (i==j)
        {
            dp[i][j] = 1;
          continue;
        }
        if (x%y == 0)
        {
          dp[x][y] = x/y;//13*29
          continue;
        }
        if (y%x == 0)
        {
          dp[x][y] = y/x;
          continue;
        }


        int minimum = INT_MAX;

        for (int k=1; k<=min(i,j); k++)
         {
          int minK = min(dp[i-k][j] + dp[k][j-k],dp[i][j-k]+dp[i-k][k]);//horisontal vertical cut
          minimum = min(minimum, minK);
        }
        dp[i][j] = 1+minimum;
      }
    }

    return dp[x][y];
  }
  int main()
  {
      cout<<minSquares(13,29);
  }
