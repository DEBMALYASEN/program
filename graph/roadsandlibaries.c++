#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];
long nodes;

void DFS(int n)
{
    nodes++;
    visited[n] = true;
    for(auto i:adj[n])
    {
        if(!visited[i])
            DFS(i);
    }
}


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N,M,a,b;
        long X,Y;
        cin >> N >> M >> X >> Y;
// x road y lib
        for(int i=0 ; i<=N ; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
        for(int i = 0 ; i < M ; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        long cost=0;

        for(int i = 1 ; i <= N ; i++)
        {
            if(!visited[i])
            {
                nodes = 0;
                DFS(i);
                cost = cost + X;
                if(X > Y)
                    cost = cost + (Y*(nodes-1));
                else
                    cost = cost + (X*(nodes-1));
            }
        }

        cout << cost << endl;

    }

    return 0;
}
/*
2
3 3 2 1
1 2
3 1
2 3
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6*/
