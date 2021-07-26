#include<bits/stdc++.h>
using namespace std;
int optimal_binary_Search(int val[],int freq[],int n)
{
    int dp[100][100];
    for(i=0;i<n;i++)
    dp[i][i]=freq[i];

    for (int L = 2; L <= n; L++)
   {
       // i is row number in cost[][]
       for (int i = 0; i <= n-L+1; i++)
       {
           // Get column number j from row number i and
           // chain length L
           int j = i+L-1;
           cost[i][j] = INT_MAX;

           // Try making all keys in interval keys[i..j] as root
           for (int r = i; r <= j; r++)
           {
           // c = cost when keys[r] becomes root of this subtree
           int c = ((r > i)? cost[i][r-1]:0) +
                   ((r < j)? cost[r+1][j]:0) +
                   sum(freq, i, j);
           if (c < cost[i][j])
               cost[i][j] = c;
           }
       }
   } 
}
