#include<bits/stdc++.h>
using namespace std;
/*
The key to solving this problem is to use a sliding window. We can keep track of our sliding window by have a left
 and right that tracks the window. The right start from position 0 along with the left, and will continuely be moved to
  the right by one position after each iteration. Since we want to find out the max sequence of 1's given the ability to
   flip the zeros k times, we only have to change the left variable to update our window. Additionally we don't have to
   actually flip the zeros, we can just pretend to flip them and keep track of how many we "flipped". We iterate through
    the array until we encounter a zero and "flip" that zero. After that we check to make sure that we haven't "flipped"
     more than k zeros. if we have, then we need to decrease that number. We can do that by moving the left side until it
      encounters a zero and can "unflip" it. This will allow us to not have flipped more than k zeros and will provide us
       with the max subarr of sequential 1's. At the end of each iteration we check to see if the current length of the
       sub array right - left + 1(Plus one because we want to include the 1 at position left which is normally excluded
        when doing right - left) is greater than maxCount and if it is, we need to update maxCount. After iterating through
        all the elements we return maxCount which holds the max length sub array of sequencial 1's.*/

int longestOnes(vector<int>& nums, int k)
{
       int left = 0, right = 0;
       int flippedZeroes = 0;
       int size = nums.size();
       int count = 0, maxCount = 0;
       for(; right < size; right++)
       {
           if(nums[right] == 0)
               flippedZeroes++;

           while(flippedZeroes > k)
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
       cout<<longestOnes(a,3);
   }
