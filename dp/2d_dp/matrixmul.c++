#include<bits/stdc++.h>
using namespace std;
void matmul(int a[] ,int n)
{
    int dp[100][100]={0};


    for(int i=0;i<n;i++)
    dp[i][i]=0;
    int q=0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i <= n -l; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <j; k++)
            {

                q = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];

                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<n;j++)
            cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        //return dp[n-1][sum];

}

int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    matmul(a,n);
}
