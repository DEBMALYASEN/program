#include<bits/stdc++.h>
using namespace std;

int maxRevenue(int m, int x[], int revenue[], int n,int t)
{
    int dp[1000]={0};
    int nxtbb = 0;//min dis b/w 2 billboards
    for (int i = 1; i <= m; i++)
    {
        if (nxtbb < n)//number of billboards not finished
        {
            if (x[nxtbb] != i)// this line is not a billboard
                dp[i] = dp[i-1];

            else//billboard encountered
            {
                if (i <= t)   /*If current position is less than or equal to t, then we can have only one billboard.*/
                    dp[i] = max(dp[i-1], revenue[nxtbb]);
                else           /*Else we may have to remove previously placed  billboard  */
                    dp[i] = max(dp[i-t-1]+revenue[nxtbb],dp[i-1]);
                nxtbb++;
            }
        }
        else
            dp[i] = dp[i - 1];// number of billboards has finished
    }

    return dp[m];
}
int main()
{
    int m;
    cin>>m;
    int n;
    cin>>n;
    int x[100],revenue[100];
    for(int i=0;i<n;i++)
    cin>>x[i];
    for(int i=0;i<n;i++)
    cin>>revenue[i];
    int t;
    cin>>t;
    cout << maxRevenue(m, x, revenue, n, t) << endl;
    return 0;
}
