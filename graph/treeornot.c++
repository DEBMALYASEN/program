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
    bool cycle_helper(T src,map<T,bool>&visited,T parent)
    {

        visited[src]=true;

        for(T nbr:l[src])
        {
            if(!visited[nbr])
            return cycle_helper(nbr,visited,src);
            else if(nbr!=parent)
            return true;
        }
        return false;
    }
    bool istree()
    {
        map<T,bool>visited ;
        for(auto i:l)
            visited[i.first]=false;


        if(  cycle_helper(0,visited,1))
        return false;
         for(auto i:l)
         {
             if(!visited[i.first])
             return false;
         }
         return true;


    }
};
int main()
{
    graph <int>g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);



    cout<<g.istree();

}
