#include<bits/stdc++.h>
using namespace std;


int longestOnes(vector<int>& nums)
{
       int left = 0, right = 0;
       int flippedZeroes = 0;
       int size = nums.size();
       int count = 0, maxCount = 0;
       for(; right < size; right++)
       {
           if(nums[right] == 0)
               flippedZeroes++;

           while(flippedZeroes > 1)
           {
               if(nums[left] == 0)
                   flippedZeroes--;
               left++;
           }

           count = right-left + 1;

           if(count > maxCount)
               maxCount = count;
       }
       return maxCount;
   }
   int main()
   {
       vector<int> a={0,0,1,1,0,0,1,0,0,1,0,1,1};
       cout<<longestOnes(a);
   }
