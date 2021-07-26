#include<bits/stdc++.h>
using namespace std;
int arrayNesting(vector<int>& nums)
   {
  int n = nums.size(), maxi = 1;
   vector<bool>vis(n, false);

   for(int i=0;i<n;i++)
   {
       int x = i, count = 0;
       if( !vis[x])
       {
           while( !vis[x])
           {
               count++;
               vis[x] = true;
               x = nums[x];
           }
           maxi = max(maxi, count);
       }
       else continue;
   }
   return maxi;
   }
   int main()
   {
       vector<int>a={5,4,0,3,1,6,2};
       cout<<arrayNesting(a);
   }
