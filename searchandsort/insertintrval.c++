#include<bits/stdc++.h>
using namespace std;
void insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>res.back()[1])
                res.push_back(intervals[i]);
            else
                res.back()[1]=max(res.back()[1],intervals[i][1]);
        }
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";

            cout<<endl;
        }

    }
    int main()
    {
        vector<vector<int>>a={{1,2},{3,5},{6,7},{8,10},{12,16}};
        vector<int>in={4,8};
        insert(a,in);

    }
