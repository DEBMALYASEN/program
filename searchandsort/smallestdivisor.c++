#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int>& nums, int div, int threshold)
{
    long long sum = 0;
    for(int i : nums)
        sum += ceil(((double)i)/div);

    return (sum <= threshold);
}
int smallestDivisor(vector<int>& nums, int threshold)
{
        long long low = 1, high = 1e9+1, mid;

        while(low < high)
        {
            mid = low + (high-low)/2;
            if(possible(nums, mid, threshold))
            high = mid;
            else
            low = mid+1;
        }
        return low;
}


    int main()
    {
        vector<int>nums={1,2,5,9};
        int thrshold=6;
        cout<<smallestDivisor(nums,thrshold);
    }
