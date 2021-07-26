#include<bits/stdc++.h>
using namespace std;
int parent[10000];
int rank[10000];
void makeset(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
     }

}
int findpar(int node)
{
    if(node==parent[node])
    return node;

    return parent[node]=findpar(parent[node]);
}
void union(int u,int v)
{
    u=findpar(u);
    v=findpar(v);
    if(rank[u]<rank[v])
    parent[u]=v;
    else if(rank[v]<rank[u])
    parent[v]=u;
    else
    {
    parent[v]=u;
    rank[u]++;
    }
}
int main()
{   int n;
    cin>>n;
    makeSet(n);
    cin>>m;
    while(m--)
    {
        int u,v;
        union(u,v);
    }

    if(findpar())
}
