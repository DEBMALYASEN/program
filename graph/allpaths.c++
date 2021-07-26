#include<bits/stdc++.h>
using namespace std;
template<class T>
class graph
{
    map<T,list<T>> l;
public:
    void add_edge(T x,T y ,int directed=true)
    {
        l[x].push_back(y);
        if(!directed)
        l[y].push_back(x);
    }
    int count_paths(int src,int des)
    {
        int path_count=0;
        path_counter(src,des,path_count);
        return path_count;
    }
    void path_counter(int src, int dst, int& path_count)
    {

    if (src == dst)
        path_count++;

    else
    {
        for (auto nbr : l[src])
            path_counter(nbr, dst, path_count);

    }
       }
};
int main()
{
    graph<int> g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(2, 4);

   cout<<g.count_paths(0, 3);

    return 0;
}
