#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target)
{

    int l=0,r=nums.size()-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>=nums[l])
        {
            if(target>=nums[l] && target<=nums[mid])
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        else
        {
            if(nums[mid]<=target && nums[r]>=target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int>a={4,5,1,2,3};
    cout<<search(a,5);
}
