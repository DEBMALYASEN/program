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
    bool bipartite_helper(T src,map<T,int>&color_visited,T color,T parent)
    {

        color_visited[src]=color;

        for(T nbr:l[src])
        {
            if(color_visited[nbr]==0)
            return bipartite_helper(nbr,color_visited,3-color,src);
            else if(nbr!=parent and color==color_visited[nbr])//2 having same color
            return false;
        }
        return true;
    }
    bool isbipartite(T src)
    {
        map<T,int >color_visited ;
        for(auto i:l)
            color_visited[i.first]=0;
        int color=1;

        T parent =2;
        return  bipartite_helper(src,color_visited,color,parent);

    }
};
int main()
{
    graph <int>g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);


    cout<<g.isbipartite(0);

}
