#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target)
    {

             vector<int>ans(2,-1);


        int start=0,last=nums.size()-1;

             int ans1=-1;

        while(start<=last&&start>=0)
        {

            int mid=(start+last)/2;


            if(nums[mid]>target)
            {
                last=mid-1;

            }
           else  if(nums[mid]==target)
            {
                last=mid-1;
                 ans1=mid;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }

        }



        if(ans1!=-1)
            ans[0]=ans1;



               start=0,last=nums.size()-1;
        ans1=-1;

        while(start<=last&&start>=0)
        {
            int mid=(start+last)/2;
            if(nums[mid]>target)
            {
                last=mid-1;
            }
           else if(nums[mid]<target)
            {
                start=mid+1;
            }
                else if(nums[mid]==target)
            {
                ans1=mid;
                start=mid+1;
            }
        }



       if(ans1!=-1)
            ans[1]=ans1;


        return ans;

    }
    int main()
    {
        vector<int>a={5,7,7,8,8,8,10};
        cout<<searchRange(a,8)[0]<<" "<<searchRange(a,8)[1];
    }
