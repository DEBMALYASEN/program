#include<bits/stdc++.h>
using namespace std;
template<class T>
class graph//directed connected
{
    map<T,list<T>> l;
public:
    void addEdge(T x,T y ,int directed=false)
    {
        l[x].push_back(y);
        if(!directed)
        l[y].push_back(x);
    }


    void dfs_helper(map<T,bool>& visited,T src)
    {

        visited[src]=true;

        for(auto nbr:l[src])
        {
            if(!visited[nbr])
                dfs_helper(visited,nbr);

        }
    }
    int nonreachable(T v)
    {

        map<T,bool>visited;


        for(auto i:visited)
        visited[i.first]=false;

        dfs_helper(visited,v);

          int c=0;

        for(auto i:l)
        {
        if(!visited[i.first])
        c++;
        }
    return c;

    }
};





    int main()
{

    graph<int> g;
g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(6, 7);

    cout << "non reachable" << g.nonreachable(5);

    return 0;
}
