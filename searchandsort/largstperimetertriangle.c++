#include<bits/stdc++.h>
using namespace std;



int largestPerimeter(vector<int>& nums)
{
       sort(begin(nums), end(nums));
       for (int i = (nums).size()-1; i >= 2; --i)
           if (nums[i-2] + nums[i-1] > nums[i])
               return nums[i-2] + nums[i-1] + nums[i];
       return 0;
  }
  int main()
  {
      vector<int>z={3,2,3,4};
      cout<<largestPerimeter(z);
  }
