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
    bool cycle_helper(T src,map<T,bool>&visited,map<T,bool>&stack)
    {

        visited[src]=true;
        stack[src]=true;

        for(T nbr:l[src])
        {
            if(stack[nbr]==true)
            return true;
            else if (!visited[nbr])
            {
                bool cycle_mila=cycle_helper(nbr,visited,stack);
                if(cycle_mila==true)
                return true;
            }
        }
        stack[src]=false;
        return false;
    }
    bool iscycle()
    {
        map<T,bool>visited ;
        map<T,bool>stack;
        for(auto i:l)
        {
            visited[i.first]=false;
            stack[i.first]=false;
        }


        return  cycle_helper(0,visited,stack);



    }
};
int main()
{
    graph <int>g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    //g.addEdge(5,0);


    cout<<g.iscycle();

}
