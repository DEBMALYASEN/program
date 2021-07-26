#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums)
{
        int left_sum=0;
        for(int i=0;i<nums.size();i++)
            left_sum+=nums[i];
        int right_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            left_sum-=nums[i];
            if(left_sum==(right_sum))
                return i;
            right_sum+=nums[i];
        }
        return -1;
    }
    int main()
    {
        vector<int>a={1,7,3,6,5,6};
        cout<<pivotIndex(a);
    }
