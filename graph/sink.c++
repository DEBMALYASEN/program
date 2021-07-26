
#include<bits/stdc++.h>
using namespace std;
int countSink(int n, int m, int edgeFrom[],int edgeTo[])
{

   int mark[100];

   for (int i = 0; i < m; i++)
       mark[edgeFrom[i]] = 1;

   int count = 0;
   for (int i = 1; i <= n ; i++)
       if (!mark[i])
           count++;

   return count;
}

int main()
{
   int n = 4, m = 2;
   int edgeFrom[] = { 2, 4 };
   int edgeTo[] = { 3, 3 };

   cout << countSink(n, m, edgeFrom, edgeTo) << endl;

   return 0;
}
