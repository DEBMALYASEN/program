#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

vector<int> adj[100000];
int visited[100000];


void DFS(int u)
{
   visited[u] = 1;


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
  vector<vector<int>>a={{1,1,0},{1,1,0},{0,0,1}};

for(int i=0;i<a.size();i++)
{
    for(int j=0;j<a[i].size();j++)
    {
           if(a[i][j])
           {
            adj[i].push_back(j);
            }
    }
}



int ans=0;

   for(int
   i=0;i<a.size();i++)
   {
       if(!visited[i])
       {
           DFS(i);

          ans++;

       }
   }

   cout<<ans<<" ";
   return 0;
}
