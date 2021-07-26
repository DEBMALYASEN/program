#include<bits/stdc++.h>
using namespace std;
int mobile(vector<vector<int>> data,int n)
{
    int dp[100][100],i,j;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=9;j++)
        {
            if(i==1)
            dp[i][j]=1;
            else
            {
             for(int k: data[j] )
             dp[i][j]+=dp[i-1][k];
            }
        }
    }
    int sum=0;
        for(j=0;j<=9;j++)
        {

          sum+=dp[n][j];
        }
    return sum;


}

  int main()
  {
  int n;
  cin>>n;
      vector<vector<int>>data={{0,8},
                         {1,2,4} ,
                        {1,2,3,5},
                        {2,3,6} ,
                        {1,4,5,7},
                        {2,4,5,6,8} ,
                        {3,5,6,9},
                         {4,7,8},
                         {5,7,8,9,0},
                          {6,8,9}   };

     cout<< mobile(data,n);

  }
