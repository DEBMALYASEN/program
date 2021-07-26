#include<bits/stdc++.h>
using namespace std;
template<class T>
class graph//directed connected
{
    map<T,list<T>> l;
public:
    void addEdge(T x,T y ,int directed=true)
    {
        l[x].push_back(y);
        if(!directed)
        l[y].push_back(x);
    }
   void printallpaths(int s,int d)
   {
       map<T,bool>visited;
       int path[100]={0};

       for(auto i:visited)
       visited[i.first]=false;

       int path_index=0;
       printAllPaths_helper(s, d, visited, path, path_index);

   }
   void printAllPaths_helper(int s ,int d,map<T,bool>&visited,int (&path)[100],int &path_index)
   {
    visited[s] = true;
    path[path_index] = s;
    path_index++;

    if(s==d)
    {
        for (int i = 0; i < path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else
    {
        for(auto nbr: l[s])
        {
            if(!visited[nbr])
            printAllPaths_helper( nbr, d,visited,path,path_index);
        }
    }
    path_index--;
    visited[s]=false;

   }
};
   int main()
{
    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int s = 2, d = 3;
    cout << "Following are all different paths from " << s << " to " << d << endl;
    g.printallpaths(s, d);

    return 0;
}
