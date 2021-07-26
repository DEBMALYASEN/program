#include<bits/stdc++.h>
using namespace std;
void wiggleSort(vector<int>& nums)
{

       vector<int> temp = nums;
       sort(temp.begin(), temp.end());

       int i = (temp.size()-1)/2;
       int j = temp.size()-1;
       int k = 0;
       while(k < nums.size())
       {
           if(k&1)
               nums[k++] = temp[j--];
           else
               nums[k++] = temp[i--];
       }

   }
   int main()
   {
       vector<int>a={1,3,2,2,3,1};
       wiggleSort(a);
       for(auto i:a)
       cout<<i<<" ";
   }
