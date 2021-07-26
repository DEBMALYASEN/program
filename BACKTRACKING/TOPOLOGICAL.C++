
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    vector<int> indegree;

    void helper(vector<int>& res,bool visited[]);

public:
    Graph(int V);

    void addEdge(int v, int w);

    void alltopologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    for (int i = 0; i < V; i++)
        indegree.push_back(0);
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    indegree[w]++;
}

void Graph::helper(vector<int>& res, bool visited[])
{


    for (int i = 0; i < V; i++)
    {

        if (indegree[i] == 0 && !visited[i])
        {

            for (auto j :adj[i])
                indegree[j]--;

            res.push_back(i);
            visited[i] = true;



            helper(res, visited);

            visited[i] = false;
            res.erase(res.end() - 1);

            for (auto j :adj[i])
                indegree[j]++;



        }
    }


    if (res.size()==V)
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}

void Graph::alltopologicalSort()
{

    bool visited[V]={0};
    vector<int> res;
    helper(res, visited);
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "All Topological sorts\n";

    g.alltopologicalSort();

    return 0;
}
