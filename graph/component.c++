#include<bits/stdc++.h>
using namespace std;
template<class T>
class graph
{
    map<T,list<T>> l;
public:
    void addEdge(T x,T y ,int directed=false)
    {
        l[x].push_back(y);
        if(!directed)
        l[y].push_back(x);
    }
    void dfs_helper(T src,map<T,bool>&visited)
    {
    cout<<src<<" ";
        visited[src]=true;

        for(T nbr:l[src])
        {
            if(!visited[nbr])
            dfs_helper(nbr,visited);
        }
    }
    void dfs()
    {
        map<T,bool>visited ;
        for(auto i:l)
            visited[i.first]=false;

int c=1;
        for(auto i:l)
        {
            if (!visited[i.first])
            {

            dfs_helper(i.first,visited);
            cout<<"Component"<<c++<<" ";
            cout<<endl;
            }
        }
    }
};
int main()
{
    graph <int>g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(5,4);
    g.addEdge(4,6);
    g.addEdge(6,7);
    g.addEdge(10,11);
    g.addEdge(12,11);

    g.dfs();

}
