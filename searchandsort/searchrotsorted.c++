#include<bits/stdc++.h>
using namespace std;
    bool search(vector<int>& nums, int target)
     {
        int n = nums.size();
        if (n == 0)
            return false;

        int left = 0;
        int right = n - 1;
        int mid = 0;

        while (left <= right)
        {
            mid = left + (right-left) / 2;

            if (target == nums[mid])
                return true;

            if (nums[left] < nums[mid])
            {
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left  = mid + 1;
            }
            else if (nums[left] > nums[mid])
            {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
                ++left;
        }

        return false;
    }
    int main()
    {
        vector<int>a={4,4,5,1,2,3};
        cout<<search(a,4);
    }
