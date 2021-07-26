#include<bits/stdc++.h>
using namespace std;
vector<int> findOrder(int V, vector<vector<int>>& prerequisites)
{

    vector<int> adj[V];

    for(auto v : prerequisites)
        adj[v[1]].push_back(v[0]);

    vector<int> inDegree(V);

    for(int u = 0; u < V; ++u)
    {
        for(auto v : adj[u])
            inDegree[v]++;
    }

    queue<int> q;

    for(int i=0; i<V; ++i)
        if(inDegree[i] == 0)
            q.push(i);

    int ctr = 0;
    vector<int> res;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);

        for(auto &v : adj[u])
        {
            inDegree[v]--;
            if(inDegree[v] == 0)
                q.push(v);
        }
        ctr++;
    }

    vector<int> empty;
    if(ctr != V)
        return empty;
    else
        return res;
}

int main()
{
    vector<vector<int>> a={{1,0},{2,0},{3,1},{3,2}};
    vector<int>x=findOrder(4,a);
    for(auto i:x)
    cout<<i<<" ";
}
