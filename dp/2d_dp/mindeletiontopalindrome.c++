#include<bits/stdc++.h>
using namespace std;

void minDeletions(string X)
{
    string Y = X;
    int n=X.size();
    reverse(Y.begin(), Y.end());

    int dp[1000][1000];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;


    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        }
    }


   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=n;j++)
       cout<<dp[i][j]<<" ";
       cout<<endl;
   }

}

int main()
{
    string X = "GEEKS";


            minDeletions(X);

    return 0;
}
