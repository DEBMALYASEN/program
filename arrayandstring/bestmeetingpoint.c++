
#include <bits/stdc++.h>
using namespace std;

   int minTotalDistance(vector<vector<int>>& grid)//manhattan dis
    {
      vector<int> row;
      vector<int> col;
      for (int i = 0; i < grid.size(); i++)
      {
         for (int j = 0; j < grid[0].size(); j++)
         {
            if (grid[i][j])
             {
               row.push_back(i);
               col.push_back(j);
            }
         }
      }
      return get(row) + get(col);
   }
   int get(vector <int> v)
   {
      sort(v.begin(), v.end());
      int i = 0;
      int j = v.size() - 1;
      int ret = 0;
      while (i < j)
      {
         ret += v[j] - v[i];
         i++;
         j--;
      }
      return ret;
   }

main(){

   vector<vector<int>> v = {{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};
   cout << minTotalDistance(v);
}
