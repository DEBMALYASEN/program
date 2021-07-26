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
    void bfs(T src)
    {
        map<T,bool>visited;
        queue<T> q;

        q.push(src);
        visited[src]=true;



        while(!q.empty())
        {
            T node =q.front();
            q.pop();
            cout<<node<<" ";
            for(auto nbr :l[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
  }
void dfs_helper(T src,map<T,bool>& visited)
{
    cout<<src<<" ";
    visited[src]=true;

    for(auto nbr:l[src])
    {
        if(!visited[nbr])
        {
            dfs_helper(nbr,visited);
        }
    }
}



  void dfs(T src)
  {
      map<T,bool>visited;

      for(auto i:l)
      {
          T node =i.first;
          visited[node]=false;
      }
      dfs_helper(src,visited);
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

    g.bfs(1);
    cout<<endl;
    g.dfs(1);

}
