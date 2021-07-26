#include<bits/stdc++.h>
using namespace std;
int maxWidthRamp(vector<int>& nums)
 {
     int n=nums.size();
     int leftmin[n],rightmax[n];

     leftmin[0]=nums[0];

     for(int i=1;i<n;i++)
         leftmin[i]=min(leftmin[i-1],nums[i]);

     rightmax[n-1]=nums[n-1];

     for(int i=n-2;i>=0;i--)
         rightmax[i]=max(rightmax[i+1],nums[i]);

     int i=0,j=0,res=0;
     while(j<n)
     {
         if(leftmin[i]<=rightmax[j])
             j++;
         else
             i++;
         res=max(res,j-i-1);
     }
     return res;
 }
 int main()
 {
     vector<int>a={1,2,0,7,1,2,7,0};
     cout<<maxWidthRamp(a);
 }
