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

void dfs_helper(T src,map<T,bool>& visited,map<T,int>&arrival,map<T,int>&departure,int &time)
{

    visited[src]=true;
    arrival[src]=++time;
    for(auto nbr:l[src])
    {
        if(!visited[nbr])
        {
            dfs_helper(nbr,visited,arrival,departure,time);
        }
    }
    departure[src]=++time;
}



  void dfs()
  {
      map<T,bool>visited;
      map<T,int>arrival;
      map<T,int>departure;
      int time=-1;

      for(auto i:l)
      {
          T node =i.first;
          visited[node]=false;
      }
      for(auto p: l )
      {
          T node=p.first;
          if(!visited[node])
          {
              dfs_helper(node,visited,arrival,departure,time);
          }
      }

      for(auto i:visited)
      cout<<i.first<<"  ";
      cout<<endl;
      for(auto i:arrival)
      cout<<i.second<<"  ";
       cout<<endl;
      for(auto i:departure)
      cout<<i.second<<"  ";
      cout<<endl;

  }
};
int main()
{
    graph <int>g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(6,7);
    g.dfs();

}
