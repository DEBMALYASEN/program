#include <bits/stdc++.h>
using namespace std;

int count(int coeff[], int k, int rhs)
{
    int dp[100][100];

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= rhs; j++)
        {
            if (i == 0)
                dp[i][j] = 0;

            else if (j == 0)
                dp[i][j] = 1;

            else if (coeff[i - 1] > j)
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - coeff[i - 1]];//excluding and includings

        }
    }

    return dp[k][rhs];
}

int main(void)
{
    int coeff[] = {1, 3, 5, 7};
    int rhs = 8;

    int k = sizeof(coeff) / sizeof(coeff[0]);

    printf("The total number of solutions is %d", count(coeff, k, rhs));

    return 0;
}
