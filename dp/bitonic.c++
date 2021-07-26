
#include<bits/stdc++.h>
using namespace std;
int lbs( int a[], int n )
{
   int i, j;

  int lis[100],lds[100];
   for (i = 0; i < n; i++)
      {
          lis[i] = 1;
          lds[i] = 1;
      }

 
   for (i = 1; i < n; i++)
      for (j = 0; j < i; j++)
         if (a[i] > a[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;

   for (i = n-2; i >= 0; i--)
      for (j = n-1; j > i; j--)
         if (a[i] > a[j] && lds[i] < lds[j] + 1)
            lds[i] = lds[j] + 1;

   int max = lis[0] + lds[0] - 1;
   for (i = 1; i < n; i++)
     if (lis[i] + lds[i] - 1 > max)
         max = lis[i] + lds[i] - 1;
   return max;
}
int main()
{
int n;
cin>>n;
int a[100];
for(int i=0;i<n;i++)
cin>>a[i];

 cout<<lbs( a, n ) ;
 return 0;
}
