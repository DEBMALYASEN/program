#include<bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k)
   {

       if(k <= 1)

           return 0;

       int prod = 1, res = 0, left = 0;

       for(int right = 0; right < nums.size(); right++)
       {


           prod *= nums[right];


           while(prod >= k)
           {
               prod /= nums[left];
               left++;
           }


           res += right - left + 1;
       }
       return res;
   }
   int main()
   {
       vector<int>a={1,2,3,7,5,2};
       cout<<numSubarrayProductLessThanK(a,7);
   }
