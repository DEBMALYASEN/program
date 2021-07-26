#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
 {

        multimap<int,pair<int,int>>m;

        vector<vector<int>>ans;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int ans=abs(i-rCenter)+abs(j-cCenter);
                m.insert({ans,{i,j}});
            }
        }
        for(auto x:m)
        {
            vector<int>t;
                t.push_back(x.second.first);
                t.push_back(x.second.second);
            ans.push_back(t);
        }
        return ans;
    }
    int main()
    {
        vector<vector<int>>a=allCellsDistOrder(3,3,1,1);
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size();j++)
            cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
