#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums)
{
       int n       = nums.size();
       int sum     = nums[0];
       int maxSum  = nums[0];

       for(int i = 1; i<n; i++)
        {
           sum     = max(sum + nums[i], nums[i]);
           maxSum  = max(maxSum, sum);
       }

       return maxSum;

  }
  int main()
  {
      vector<int>a={-1,2,3,-4,7,-6};
      cout<<maxSubArray(a);
  }
