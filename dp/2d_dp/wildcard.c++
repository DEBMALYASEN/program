
#include <bits/stdc++.h>
using namespace std;
bool strmatch(string s, string p)
{
    int n=s.size();
    int m=p.size();
    if (m == 0)
        return (n == 0);

    bool dp[n + 1][m + 1];

    dp[0][0] = true;


    for (int j = 1; j <= m; j++)
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
         {
            if (p[j - 1] == '*')
                dp[i][j]= dp[i][j - 1] || dp[i - 1][j];

            else if (p[j - 1] == '?'|| s[i - 1] == p[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}

int main()
{
    string s = "baaabab";
    string p = "*****ba*****ab";
    if (strmatch(s, p))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
