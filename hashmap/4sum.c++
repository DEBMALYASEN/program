#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target)
{

        sort(nums.begin(),nums.end());

        int i,j,k,l,n=nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;

        for(i=0;i<n-3;i++)
        {
            for(j=i+1;j<n-2;j++)
            {
                k=j+1;
                l=n-1;
                int sum=target-nums[i]-nums[j];
                while(k<l)
                {
                    if(nums[k]+nums[l]==sum)
                    {
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if(nums[k]+nums[l]>sum)
                    {
                        l--;
                    }
                    else
                        k++;
                }
            }
        }

        for(auto i:s)
            ans.push_back(i);

        return ans;
    }
    int main()
    {
        vector<int>s={1,0,-1,0,-2,2};
        vector<vector<int>> x=fourSum(s,0);
        for(int i=0;i<x.size();i++)
        {
            for(int j=0;j<x[i].size();j++)
            cout<<x[i][j]<<" ";
            cout<<endl;
        }
    }
