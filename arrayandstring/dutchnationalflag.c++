#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums)
 {
     int low = 0, high = nums.size()-1, pivot = 0;

     while( pivot<=high)
     {
         if(nums[pivot]==0)
         {

             swap(nums[pivot],nums[low]);
             pivot++; low++;
         }
        else if(nums[pivot]==2)
         {
             swap(nums[high],nums[pivot]);
              high--;
         }
         else

             pivot++;

     }
 }
 int main()
 {
     vector<int>a={1,1,0,2,0};
     sortColors(a);
     for(auto i:a)
     cout<<i<<" ";
 }
