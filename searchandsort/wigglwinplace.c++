#include<bits/stdc++.h>
using namespace std;
void wiggleSort(vector<int>& nums)
{
    for(int i=1; i< nums.size();i++)
    {
               if((i&1) == 1 && nums[i] < nums[i-1] || (i&1) == 0 && nums[i] > nums[i-1])
               swap(nums[i],nums[i-1]);
   }
}//odd pos peak
   int main()
   {
       vector<int>a={1,3,2,2,3,1};
       wiggleSort(a);
       for(auto i:a)
       cout<<i<<" ";
   }
