#include<bits/stdc++.h>
using namespace std;

 	vector<int>parent;
 	int find(int x)
    {
 		return parent[x] == x ? x : find(parent[x]);
    }

 	vector<int> findRedundantConnection(vector<vector<int>>& edges)
     {

 		int n = edges.size();

 		parent.resize(n+1, 0);
 		for (int i = 0; i <= n; i++)
 			parent[i] = i;

 		vector<int>res(2, 0);
 		for (int i = 0; i < n; i++)
         {
 			int x = find(edges[i][0]);//X WILL CONTAIN THE HEAD NODE IN WHICH NODE EDGE I 0 BELONGS
 			int y = find(edges[i][1]);
 			if (x != y)//NO CYCLE EXIST  X->Y
 				parent[y] = x;
 			else
            {//CYCLE EXIST
 				res[0] = edges[i][0];
 				res[1] = edges[i][1];
 			}
 		}

 		return res;
 	}

    int main()
    {
        vector<vector<int>>edges={{1,2},
                                  {1,3},
                                  {2,3} };

        cout<<findRedundantConnection(edges)[0]<<" "<<findRedundantConnection(edges)[1];
    }
