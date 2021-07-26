#include<bits/stdc++.h>
using namespace std;
int tupleSameProduct(vector<int>& nums)
{
       int n = nums.size();

       if(n < 4)
           return 0;


       unordered_map<int, int> m;

       int ans = 0;

       for(int i = 0; i < n - 1; i++) {
           for(int j = i + 1; j < n; j++) {
               m[nums[i] * nums[j]]++;
           }
       }


       for(auto x : m) {
           int f = x.second; // the frequency of the key
           if(f > 1)
               // Logic Behind f*(f - 1)*4 is as follows:-
               // if the frequency is more than 1, then we can select any 2 pairs of numbers in (frequency C 2) ways
               // which is (f)*(f - 1) / 2 and as there are 8 ways to rearrange any tuple, so
               // (f)*(f - 1) / 2 * 8 = (f)*(f - 1)*4
               ans += (f*(f - 1)*4);
       }
       return ans;
   }
   int main()
   {
       vector<int>a={2,3,4,6};
       cout<<tupleSameProduct(a);
   }
