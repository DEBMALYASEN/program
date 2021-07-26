#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

vector<int> adj[100000];
int visited[100000];
int vertices;

void DFS(int u)
{
   visited[u] = 1;
   vertices++;

   for(auto i:adj[u])
   {
       if(!visited[i])
       {
           visited[i] = 1;
           DFS(i);
       }
   }
}

int main()
{
   int i,m,u,v,numComponents=0,allv=0,temp=2,count=0;

    int n;

   int eachC[10000];

   cin >> n >> m;

   if(n == 1)
   {
       cout <<"0\n";
       return 0;
   }

   for(i=0;i<m;i++)
   {
       cin >> u >> v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }



   for(i=0;i<n;i++)
   {
       if(!visited[i])
       {
           vertices = 0;
           DFS(i);

           eachC[numComponents++] = vertices;

       }
   }

   int totalWays = n*(n-1) / 2;
 int sameWays = 0;

   for(i=0;i<numComponents;i++)
       sameWays = sameWays + (eachC[i]*(eachC[i]-1) / 2);

   cout << (totalWays - sameWays) << endl;
   return 0;
}
