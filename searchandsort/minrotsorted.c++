#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {

       int n = nums.size();
       int s = 0;
       int e = n-1;

       while(s<e)
       {
           int mid = (s+e)/2;

           if(nums[mid] > nums[e])
           {
               s = mid+1;
           }
           else
           {
               e = mid;
           }

       }

       return nums[s];

   }
   int main()
   {
       vector<int>a={4,5,1,2,3};
       cout<<findMin(a);
   }
