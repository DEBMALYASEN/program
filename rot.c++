#include<bits/stdc++.h>
#define R 4
#define C 4
using namespace std;
void rotate(int m,int n,int a[R][C])
{
    int x[m],i,j;
    for(i=0;i<m;i++)
    {
        x[i]=a[i][n-1];
    }
    for(i=0;i<m;i++)
    {
        for(j=n-1;j>=1;j--)
        {
            a[i][j]=a[i][j-1];
        }
    }
    for(i=0;i<m;i++)
    {
        a[i][0]=x[i];
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void transpose(int arr[R][C])
{
    for (int i = 0; i < R; i++)
        for (int j = i; j < C; j++)
            swap(arr[i][j], arr[j][i]);
}

void reverse(int a[R][C])
{
    for(int i=0;i<R/2;i++)
      {
          for(int j=0;j<C;j++)
          swap(a[i][j],a[R-i-1][j]);
      }
}
int main()
{
    // Test Case 1
    int a[R][C] = { {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16} };

    // Tese Case 2
    /* int a[R][C] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                    };
    */ rotate(R, C, a);
    return 0;
}
