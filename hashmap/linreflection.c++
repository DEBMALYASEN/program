#include<bits/stdc++.h>
using namespace std;

bool isReflected(vector<vector<int>>& points)
   {
       set<pair<int, int>> s;
       int l = points[0][0];
       int r = l;

       for (auto i = 0; i < points.size(); i++)
       {
           auto x = points[i][0];
           auto y = points[i][1];

           r = max(r, x);
           l = min(l, x);

           s.insert({x, y});
       }

       auto sum = l + r;

       for (auto p : s)
       {
           if (s.count({sum - p.first, p.second}) == 0)
               return false;
       }

       return true;
   }
   int main()
   {
       vector<vector<int>>a={{-1,1},{1,1},{0,0},{0,1},{2,2},{-2,2}};
       cout<<isReflected(a);
   }
