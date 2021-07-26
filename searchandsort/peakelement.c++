#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums)
{
      int start = 0;
      int end = nums.size()-1;

      int n = nums.size();


      while(start <=end )
      {

          int mid = start + (end-start)/2;

          int next = (mid+1)%n;
          int pre = (mid+n-1)%n;

          if(nums[mid]>= nums[next] && nums[mid] >= nums[pre])
              return mid;
          else if(nums[mid] < nums[mid+1])
              start = mid+1;
          else
              end = mid-1;


      }

      return start;
  }

  int main()
  {
      vector<int>a={1,2,3,2,0,3,7,6,5,2,0};
      cout<<findPeakElement(a);
  }
