
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    int *in;
public:

    Graph(int V);
    ~Graph()
    {
         delete [] adj;
         delete [] in;
     }


    void addEdge(int v, int w)
    {
    adj[v].push_back(w);
    in[w]++;
    }

    bool isEulerianCycle();

    bool isSC();
    void DFSUtil(int v, bool visited[]);

    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    in = new int[V];
    for (int i = 0; i < V; i++)
       in[i] = 0;
}

bool Graph::isEulerianCycle()
{
    // Check if all non-zero degree vertices are connected
    if (isSC() == false)
        return false;

    // Check if in degree and out degree of every vertex is same
    for (int i = 0; i < V; i++)
        if (adj[i].size() != in[i])
            return false;

    return true;
}

void Graph::DFSUtil(int v, bool visited[])
{

    visited[v] = true;
  for(auto i:adj[v])
  {
        if (!visited[i])
            DFSUtil(i, visited);
        }
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {

        for(auto i:adj[v])
        {
            g.adj[i].push_back(v);
            (g.in[v])++;
        }
    }
    return g;
}

bool Graph::isSC()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Find the first vertex with non-zero degree
    int n;
    for (n = 0; n < V; n++)
        if (adj[n].size() > 0)
          break;

    DFSUtil(n, visited);

    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
              return false;

    Graph gr = getTranspose();

    for (int i = 0; i < V; i++)
        visited[i] = false;

    gr.DFSUtil(n, visited);


    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
             return false;

    return true;
}
bool canBeChained(string arr[], int n)
{

    Graph g(26);

    for (int i = 0; i < n; i++)
    {
        string s = arr[i];
        g.addEdge(s[0]-'a', s[s.length()-1]-'a');
    }


    return g.isEulerianCycle();
}

int main()
{
    string arr1[] =  {"for", "geek", "rig", "kaf"};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    canBeChained(arr1, n1)?  cout << "Can be chained \n" :
                           cout << "Can't be chained \n";

    string arr2[] =  {"aab", "abb"};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    canBeChained(arr2, n2)?  cout << "Can be chained \n" :
                           cout << "Can't be chained \n";

    return 0;
}
