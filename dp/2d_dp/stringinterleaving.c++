#include <bits/stdc++.h>
using namespace std;

bool isInterleaving(string X, string Y, string S)
{
    int M = X.size();
    int N = Y.size();


    if (M + N != S.size())
        return false;

    bool dp[100][100];

    for (int i = 0; i <= M; i++)//x
    {
        for (int j = 0; j <= N; j++)//y
        {
            if (i == 0 && j == 0)             // both strings are empty
                dp[i][j] = true;


            // if the current char of `S` matches the current char of both `A` and `B`
            else if (i and j and X[i - 1] == S[i + j - 1] and Y[j - 1] == S[i + j - 1])
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];


            // if the current char of `X` matches with the current char of `S`
            else if (i and X[i - 1] == S[i + j - 1])
                dp[i][j] = dp[i - 1][j];


            // if the current char of `Y` matches with the current char of `S`
            else if (j and Y[j - 1] == S[i + j - 1])
                dp[i][j] = dp[i][j - 1];

        }
    }

    return dp[M][N];
}

int main()
{
    string X = "ABC";
    string Y = "ACD";
    string S = "ACDABC";

    if (isInterleaving(X, Y, S))
        cout << "Given string is an interleaving of X and Y";

    else
        cout << "Given string is not an interleaving of X and Y";

    return 0;
}
