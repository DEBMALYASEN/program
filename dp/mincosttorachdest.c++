#include <bits/stdc++.h>
using namespace std;


int findMinCost(int a[100][100],int n)
{
    int dp[n];

    for (int i = 0; i < n; i++)
        dp[i] = a[0][i];//from city 0 to city i



    bool is_filled = false;

    while (!is_filled)
    {
        is_filled = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i] > dp[j] + a[j][i])
                {
                    dp[i] = dp[j] + a[j][i];
                    is_filled = false;
                }
            }
        }
    }

    return dp[n-1];
}

int main()
{

    int n;
    cin>>n;
    int i,j;
    int a[100][100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cin>>a[i][j];
    }
    cout << "The minimum cost is " << findMinCost(a,n) << endl;

    return 0;
}
