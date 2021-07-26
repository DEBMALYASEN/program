#include<bits/stdc++.h>
using namespace std;
template<class T>
class graph
{
    map<T,list<T>> l;
public:
    void addEdge(T x,T y ,int directed=true)
    {
        l[x].push_back(y);
        if(!directed)
        l[y].push_back(x);
    }
    void dfs(T src,int(&out)[100],int (&in)[100],int (&visited)[100])
    {
    static int  timer;
     timer=0;
        visited[src]=1;
        ++timer;
        in[src]=timer;
        for(auto i:l[src])
        {
            if(!visited[i])
            dfs(i,out,in,visited);
        }
        ++timer;
        out[src]=timer;

    }
    bool query(int u, int v,int (&in)[100],int(&out)[100])
    {
        return ( (in[u]<in[v] && out[u]>out[v]) ||
            (in[v]<in[u] && out[v]>out[u]) );
    }
};

int main()
{
    int visited[100]={0};
    int in[100]={0};
    int out[100]={0};
    graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,6);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(5,7);
    g.addEdge(5,8);
    g.addEdge(5,9);
    g.dfs(1,out,in,visited);
    cout<<g.query(1,5,in,out)<<" "<<g.query(2,9,in,out)<<" "<<g.query(2,6,in,out);
}
