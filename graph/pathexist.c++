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
    bool bfs(T src,T des)
    {
        map<T,bool>visited;
        queue<T> q;
        if(src==des)
        return true;
        q.push(src);
        visited[src]=true;



        while(!q.empty())
        {
            T node =q.front();
            q.pop();
            for(auto nbr :l[node])
            {
              if(nbr==des)
              return true;


                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;

                }
            }
        }
        return false;
  }

};
int main()
{
    graph <int>g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(4,5);
    cout<<g.bfs(5,1);


}
