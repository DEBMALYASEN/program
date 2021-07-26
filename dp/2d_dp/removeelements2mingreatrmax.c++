#include <bits/stdc++.h>
using namespace std;

int min(int a[], int l, int h)
{
    int mn = a[l];
    for (int i=l+1; i<=h; i++)
       if (mn > a[i])
         mn = a[i];
    return mn;
}
int max(int a[], int l, int h)
{
    int mx = a[l];
    for (int i=l+1; i<=h; i++)
       if (mx < a[i])
         mx = a[i];
    return mx;
}



int minRemovalsDP(int a[], int n)
{

    int table[n][n], gap, i, j, mn, mx;

    for (gap = 0; gap < n; ++gap)
    {
        for (i = 0, j = gap; j < n; ++i, ++j)
        {
            mn = min(a, i, j);
            mx = max(a, i, j);
            table[i][j] = (2*mn > mx)? 0: min(table[i][j-1],table[i+1][j])+1;//2min>max no of removal=0; consider i,j  as l h
        }
    }
    return table[0][n-1];
}

int main()
{
  int arr[] = {20, 4, 1, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << minRemovalsDP(arr, n);
  return 0;
}
