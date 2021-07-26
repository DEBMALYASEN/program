#include<bits/stdc++.h>
using namespace std;
bool isvalid(vector<int> arr,int mid,int m)
   {
       int sum=0;
       int count=1;
       for(int i=0;i<arr.size();i++)
       {
           sum+=arr[i];
           if(arr[i]>mid)
               return false;
           if(sum>mid)
           {
               count++;
               sum=arr[i];
           }
           if(count>m)
               return false;
       }
       return true;

   }
  int splitArray(vector<int>& nums, int m) {

       int sum=0, min=0;

       for(int i=0;i<nums.size();i++) sum+=nums[i];

       int h=sum,l=*min_element(nums.begin(),nums.end());
       int res=-1;

       if(nums.size()==m)
       {
           return *max_element(nums.begin(),nums.end());
       }

       while(l<=h)
       {
           int mid=l+(h-l)/2;

           if(isvalid(nums,mid,m)==true)// m subarrays with sum>=mid
           {
               res=mid;
               h=mid-1;
           }
           else
               l=mid+1;
       }
       return res;
   }
   int main()
   {
       vector<int>a={1,2,3,4,5};
       int m=3;
       cout<<splitArray(a,m);
   }
