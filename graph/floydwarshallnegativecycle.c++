#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
bool negativecycle(int graph[4][4],int n)
{

    int dist[4][4], i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < n; k++)//4 times
     {
      //iterate over the mat
        for (i = 0; i < n; i++) {

            for (j = 0; j < n; j++)
            {

                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


    for (int i = 0; i < n; i++)
      if (dist[i][i] < 0)
            return true;// neagtive cycle


    return false;


}

int main()
{

    int graph[4][4] = { { 0, INF, -2, INF },
                        { 4, 0, 3, INF },
                        { INF, INF, 0, 2 },
                        { INF, -1, INF, 0 } };


    cout<<negativecycle(graph,4);
    return 0;
}
