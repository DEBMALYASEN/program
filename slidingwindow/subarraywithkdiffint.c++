#include<bits/stdc++.h>
using namespace std;



int help(vector<int>&a , int k){
       if( k == 0)
           return 0;

       unordered_map<int,int> map;
       int n = a.size();
       int j=0;
       int ans = 0;
       for(int i=0;i<n;i++)
       {
           map[a[i]]++;
           while(map.size() > k and j <= i)
           {
               int p = map[a[j]]--;
               if(p == 1)
                   map.erase(a[j]);
               j++;
           }



           ans += (i-j+1);
       }
       return ans;
   }
   int subarraysWithKDistinct(vector<int>& a, int k)
   {
       return help(a, k) - help(a,k-1);
   }
   int main()
   {
      vector<int>a={1,2,3,1,2} ;
      cout<<subarraysWithKDistinct(a,2);
   }
