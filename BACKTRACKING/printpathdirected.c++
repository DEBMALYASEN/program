#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int>* adj;
    void helper(int, int, bool[], int[], int&);

public:
    Graph(int V);
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}


void Graph::printAllPaths(int s, int d)
{
    bool visited[V]={0};
    int path[V]={0};
    int count=0;
    helper(s, d, visited, path, count);
}

void Graph::helper(int u, int d, bool visited[], int path[], int& count)
{

    visited[u] = true;
    path[count] = u;
    count++;

    if (u == d)
    {
        for (int i = 0; i < count; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else
    {
        for (auto i: adj[u])
            if (!visited[i])
                helper(i, d, visited, path, count);
    }

    count--;
    visited[u] = false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int s = 2, d = 3;
    cout << "Following are all different paths from " << s << " to " << d << endl;
    g.printAllPaths(s, d);

    return 0;
}
