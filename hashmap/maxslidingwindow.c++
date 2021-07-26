#include<bits/stdc++.h>
using namespace std;



vector<int> maxSlidingWindow(vector<int>& nums, int k)
 {
        priority_queue<pair<int,int>>pq;
        vector<int>res;
         int i;
        for( i=0;i<k;i++)
            pq.push({nums[i],i});

        res.push_back(pq.top().first);

        for(int j=i;j<nums.size();j++)
        {
            pq.push({nums[j],j});

            while(pq.top().second<=j-k)
             pq.pop();

            res.push_back(pq.top().first);
        }
        return res;
    }

    vector<int> maxSlidingWindow2(vector<int>& nums, int k)

    {
        deque<pair<int,int>>dq;
        vector<int>res;

        for(int i=0;i<nums.size();i++)
        {
            while(!dq.empty() && dq.back().first<nums[i])
                dq.pop_back();
            dq.push_back({nums[i],i});
            if(i>=k-1)
            {
                if(dq.front().second==i-k)
                dq.pop_front();
                res.push_back(dq.front().first);
            }
        }
        return res;
    }
    int main()
    {
        vector<int>a={1,2,3,4,5,6,7,8,9};
        vector<int>res=maxSlidingWindow(a,3);
        for(auto i:res)
        cout<<i<<" ";
    }
