#include<bits/stdc++.h>
using namespace std;
int maximumSubSquare(int a[100][100],int n)
{
    pair<int,int>dp[100][100];
    int x = 0, y = 0;
    int maxside[51][51]={0};
    for (int i = 0; i < n; i++)
    {
        x = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 'X')
                x += 1;
            else
                x = 0;
            dp[i][j].first = x;
        }
    }

    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[j][i] == 'X')
                    y += 1;
                else
                    y = 0;
                dp[j][i].second = y;
            }
        }


        int maxval = 0, val = 0;
           for (int i = 0; i < n; i++)
           {
               for (int j = 0; j < n; j++)
               {
                   val = min(dp[i][j].first, dp[i][j].second);

                   if (dp[i][j - val + 1].second >= val  && dp[i - val + 1][j].first >= val)
                       maxside[i][j] = val;
                   else
                       maxside[i][j] = 0;

                   maxval = max(maxval, maxside[i][j]);
               }
           }


           return maxval;
}
int main()
{
    int mat[6][6] = {
        { 'X', 'O', 'X', 'X', 'X', 'X' },
        { 'X', 'O', 'X', 'X', 'O', 'X' },
        { 'X', 'X', 'X', 'O', 'O', 'X' },
        { 'O', 'X', 'X', 'X', 'X', 'X' },
        { 'X', 'X', 'X', 'O', 'X', 'O' },
        { 'O', 'O', 'X', 'O', 'O', 'O' },
    };

    
    cout << maximumSubSquare(mat,6);
    return 0;
}
