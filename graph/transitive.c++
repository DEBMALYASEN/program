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
    void dfs_helper(T s,T d,int tc[100][100])

    {

        tc[s][d]=1;

        for(auto nbr:l[d])
        {
            if(!tc[s][nbr])
                dfs_helper(s,nbr,tc);

        }
    }

    void transitiveClosure()
    {
        int tc[100][100]={0};
        for (auto i:l)
            dfs_helper(i.first, i.first,tc);

        for (auto i:l)
        {
            for (auto j:l)
                cout << tc[i.first][j.first] << " ";
            cout << endl;
        }
    }
};
int main()
{

    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Transitive closure matrix is \n";
    g.transitiveClosure();
    return 0;
}
