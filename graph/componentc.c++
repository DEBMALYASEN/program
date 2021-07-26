#include<bits/stdc++.h>
using namespace std;

    void dfs(vector<vector<int>>& graph,vector<bool>& vis,int src)
    {
        if(vis[src])
        return;
        vis[src]=true;
        for(int i=0;i<vis.size();i++)
        {
            if(graph[src][i]==1 && !vis[i] && i!=src)
                dfs(graph,vis,i);
        }

    }


    int findCircleNum(vector<vector<int>>& graph)
    {
        int ans=0;
        int n=graph.size();
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[j] && graph[i][j]==1 )
                {
                    dfs(graph,vis,j);
                    ans++;//connected component
                }
            }
        }
        return ans;
    }
     int main(int argc, char* argv[])
    {
        vector<vector<int>>v={{1,0,0},
                               {0,1,0},
                               {0,0,1}};
    cout<<findCircleNum(v);
        return 0;
    }
