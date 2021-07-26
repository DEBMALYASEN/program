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

    void shortestdistance(T src)
    {
        map<T,int>dist;
        queue<T> q;
        q.push(src);
        for(auto i:l)
        {
            T node=i.first;
            dist[node]=INT_MAX;
        }
        dist[src]=0;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(auto nbr:l[node])
            {  if(dist[nbr]==INT_MAX)
            {
                q.push(nbr);
                dist[nbr]=dist[node]+1;
            }
            }

        }
        for (auto i:dist)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }

    }
};
int main()
{
    graph <int>g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.shortestdistance(1);
    cout<<endl;


}
