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
    void dfs_helper(T src,map<T,bool>& visited)
    {

        visited[src]=true;

        for(auto nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr,visited);
            }
        }
    }



     int  dfs()
      {
          map<T,bool>visited;

          for(auto i:l)
          {
              T node =i.first;
              visited[node]=false;
          }
          int c=0;
          for(auto i:l)
          {
              if(!visited[i.first])
              {
                 dfs_helper(i.first,visited);
                 c++;
             }
      }
      return c;
     }
 };
 int main()
 {
     graph<int> g;
     g.addEdge(0,1);
     g.addEdge(0,2);
     g.addEdge(3,4);
     g.addEdge(5,6);
     cout<<g.dfs();
 }
