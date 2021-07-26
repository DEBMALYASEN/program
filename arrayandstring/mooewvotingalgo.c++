#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums)
{

        int count=0,element=nums[0];//concerned element
        int size=nums.size();
        for(int i=1;i<size;i++)
        {
            if(element==nums[i])
                count++;
            else
            {
                if(count==1)
                {
                    element=nums[i];
                    count=1;
                }
                else
                count--;
            }
        }
        int counter=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==element)
                counter++;
        }
        return counter>size/2 ? element : -1;
    }
    int main()
    {
        vector<int>A={3,2,3};
        cout<<majorityElement(A);
    }
