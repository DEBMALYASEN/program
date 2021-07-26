#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
        int add = 0, ans =0;

        for(int i =0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                add++;

            else
                add = 0;

            ans = max(ans, add);
        }

        return ans;
    }
    int main()
    {
        vector<int> a={0,0,1,1,0,0,1,0,0,1,0,1,1};
        cout<<findMaxConsecutiveOnes(a);
    }
