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
    void dfs_helper(map<T,bool>&visited,T src,list<T>&ordering)
    {
        visited[src]=true;
        ordering.push_front(src);
        for(auto nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(visited,nbr,ordering);
            }
        }

    }
    void dfs()
    {
        map<T,bool>visited;
        list<T>ordering;
        for(auto i:visited)
        visited[i.first]=false;

        for(auto p: l )
        {
            T node=p.first;
            if(!visited[node])
            {
                dfs_helper(visited ,node ,ordering);
            }
        }
        for(auto i:ordering)
        {
            cout<<i<<endl;
        }
    }
};
    int main()
    {
        graph<int>g;
        g.addEdge(1,2);

        g.addEdge(1,4);
        g.addEdge(4,5);
    
        g.addEdge(5,6);
        g.dfs();

    }
