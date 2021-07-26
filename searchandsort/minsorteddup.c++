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
           else if(nums[mid]<nums[e])
           {
               e = mid;
           }
           else
           {
               e--;
           }

       }

       return nums[s];

   }
   int main()
   {
       vector<int>a={4,4,4,5,5,5,5,5,1,1,1,1};
       cout<<findMin(a);
   }
