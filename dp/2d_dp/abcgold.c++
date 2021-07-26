
#include<bits/stdc++.h>
using namespace std;

int getMaxGold(int gold[100][100], int m, int n)
{

    int goldTable[100][100]={0};


    for (int col=n-1; col>=0; col--)
    {
        for (int row=0; row<m; row++)
        {
            int right = (col==n-1)? 0: goldTable[row][col+1];


            int right_up = (row==0 || col==n-1)? 0:
                            goldTable[row-1][col+1];

            int right_down = (row==m-1 || col==n-1)? 0:
                             goldTable[row+1][col+1];

            goldTable[row][col] = gold[row][col] + max(right, max(right_up, right_down));

        }
    }

    int res = goldTable[0][0];
    for (int i=1; i<m; i++)
        res = max(res, goldTable[i][0]);
    return res;
}

int main()
{

   int m,n;
   int a[100][100];
   cin>>m>>n;
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       cin>>a[i][j];
   }
    cout << getMaxGold(a, m, n);
    return 0;
}
