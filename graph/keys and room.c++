#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>>& rooms, vector<int>& visited)
   {
       visited[v] = 1;
       for(int child : rooms[v])
       {
           if(visited[child]==0)
           {
               dfs(child, rooms, visited);
           }
       }
   }

   bool canVisitAllRooms(vector<vector<int>>& rooms)
   {
       int count=0;
       int n = rooms.size();
       vector<int> visited(n,0);
       for(int i=0;i<n;i++)
       {
           if(visited[i]==0)
           {
               count++;
               dfs(i,rooms,visited);
           }
       }

       return (count==1) ? true : false;
   }

   int main()
   {
       vector<vector<int>>rooms={{1},
                                 {2},
                                  {3},
                                  {}};
    cout<<canVisitAllRooms(rooms);

   }
