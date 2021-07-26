#include<bits/stdc++.h>
using namespace std;

void bellNumber(int n)
{
   int bell[100][100];
   bell[0][0] = 1;
   for (int i=1; i<=n; i++)
   {
      bell[i][0] = bell[i-1][i-1];

      for (int j=1; j<=i; j++)
         bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
   }
   int i,j;
  for(i=0;i<n;i++)
  {
      for(j=0;j<=i;j++)
      cout<<bell[i][j]<<" ";
        cout<<endl;
  }

}


int main()
{
  bellNumber(5);
}
