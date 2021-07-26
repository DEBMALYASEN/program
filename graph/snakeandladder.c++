#include<bits/stdc++.h>
using namespace std;
template<class T>
class graph
{
    map<T,list<T>> l;
public:
    void addEdge(T x,T y)
    {
        l[x].push_back(y);

    }

    int bfs(T src,T des)
    {
        map<T,int>dist;
        queue<T> q;

        for(auto i:l)
        {
            T node=i.first;
            dist[node]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(auto nbr:l[node])
            {
               if(dist[nbr]==INT_MAX)
                  {
                         q.push(nbr);
                          dist[nbr]=dist[node]+1;
                   }
            }

        }

        for(auto i:l)
        {
            cout<<i.first<<" distance"<<dist[i.first]<<endl;
        }

        return dist[des];


    }
};

int main()
{
       int board[50] ={0};

        board[2] = 13;
        board[5] = 2;
        board[9] = 18;
        board[18] = 11;
        board[17] = -13;
        board[20] = -14;
        board[24] = -8;
        board[25] = 10;
        board[32] = -2;
        board[34] = -22;



        graph<int> g;
        g.addEdge(36,36);
        for(int i=0;i<=36;i++)
        {
            for(int dice=1;dice<=6;dice++)
            {
                int j=i+dice;
                j+=board[j];
                if(j<=36)
                {
                    g.addEdge(i,j);
                }
            }
        }
        g.bfs(3,36);


}
