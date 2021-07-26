
#include <bits/stdc++.h>
using namespace std;

class Graph
 {

    void DFSUtil(int v);

public:
    int V;
    Graph(int V)
    {
        this=>V=V;
    }
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS();
    int findMother();
};


void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v)
{

    visited[v] = true;
    cout << v << " ";

    for ( auto i :adj[v])
        if (!visited[i])
            DFSUtil(i);
}

void Graph::DFS()
{

    for (auto i:adj)
        if (!visited[i.first])
            DFSUtil(i.first);
}
void Graph::BFS(int s)
{


    visited.clear();
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto i:adj[s])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}
int Graph::findMother()
{
    visited.clear();
    int v = 0;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSUtil(i);
            v = i;
        }
    }
    visited.clear();
    DFSUtil(v);
    for (int i=0; i<V; i++)
        if (!visited[i] )
            return -1;

    return v;
}

int main()
{


    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout << "Following is Depth First Traversal \n";
    g.DFS();
    cout<<endl;

    cout << "Following is Breadth First Traversal \n";
    g.BFS(2);

    cout<<endl;
    cout<<g.findMother();

    return 0;
}
