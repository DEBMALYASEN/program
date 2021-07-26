#include<bits/stdc++.h>
using namespace std;
int arrayPairSum(vector<int>& nums)
 {
       sort(nums.begin(),nums.end());
       int n=nums.size(),res=0;
       for(int i=0;i<n;i=i+2)
       {
           res+=nums[i];
       }
       return res;
  }
  int main()
  {

      vector<int>a={5,2,3,7,5,7};
      cout<<arrayPairSum(a);
  }
