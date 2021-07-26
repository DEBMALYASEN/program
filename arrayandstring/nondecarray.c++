#include<bits/stdc++.h>
using namespace std;
bool checkPossibility(vector<int>& nums)
    {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                 if(i-1>=0&&nums[i-1]>nums[i+1])
                {
                    nums[i+1]=nums[i];
                }
                else
                {
                    nums[i]=nums[i+1];
                }
                break;
            }
        }


        /* for(auto i:nums)
         cout<<i<<" ";*/


      for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                return false;
            }
        }
        return true;

    }
    int main()
    {
        vector<int>a={5,4,6,3};
        cout<<checkPossibility(a);
    }
