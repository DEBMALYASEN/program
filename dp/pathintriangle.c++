#include<bits/stdc++.h>
using namespace std;

int maxPathSum(int a[100][100], int n)
{
     for (int i=n-1; i>=0; i--)
     {
        for (int j=0; j<=i; j++)
        {

            if (a[i+1][j] > a[i+1][j+1])
                a[i][j] += a[i+1][j];
            else
                a[i][j] += a[i+1][j+1];
        }
     }

     return a[0][0];
}

int main()
{
 int a[100][100];
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 cin>>a[i][j];

 cout << maxPathSum(a,n);
  return 0;
}
