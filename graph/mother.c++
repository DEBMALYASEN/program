#include<bits/stdc++.h>
using namespace std;
template<class T>
class graph//directed connected
{
    map<T,list<T>> l;
public:
    void addEdge(T x,T y ,int directed=true)
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
    bool mother()
    {

        map<T,bool>visited;


        for(auto i:visited)
        visited[i.first]=false;
        int v=0;
        for(auto p: l )
        {
            T node=p.first;
            if(!visited[node])
            {
                dfs_helper(visited ,node);//last finished vertex is v  if a mother vertex exist then v must be one of them ,let check wherher all vertices can be reached from it
                v=node;
            }
        }


        for(auto i:visited)
        visited[i.first]=false;


        dfs_helper(visited,v);

        for(auto i:visited)
        {
        if(!visited[i.first])
        return -1;
        }
    return v;

    }
};





    int main()
{

    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout << "A mother vertex is " << g.mother();

    return 0;
}
