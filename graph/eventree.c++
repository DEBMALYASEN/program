#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool visit[105];
int n,m;
int ans;

int dfs(int node)
{
    visit[node]=true;
    int num_vertex=0;

    for(auto i:adj[node])  
    {
        if(!visit[i])
        {
            int num_nodes=dfs(i);
            if(num_nodes%2==0)
                ans++;
            else
                num_vertex+=num_nodes;
        }
    }
    return num_vertex+1;
}

int main()
{
    int x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    cout<<ans;
    return 0;
}
