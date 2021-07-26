#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>>& p, int k)
  {
      priority_queue<pair<int, pair<int, int>>> pq;
      


          for(int i=0;i<p.size();i++)
        {
          int dist=pow(p[i][0],2)+pow(p[i][1],2);

          pq.push({dist,{p[i][0],p[i][1]}});

          if(pq.size()>k)
              pq.pop();

        }
      vector<vector<int>> res;

      while(k--)
      {
          pair<int, int> a=pq.top().second;
          res.push_back({a.first,a.second});
          pq.pop();
      }

      return res;
  }
int main()
{
    vector<vector<int>>k={{1,2},{0,2},{-1,5},{7,8},{-2,3}};
    int t=2;
    vector<vector<int>>a=kClosest(k,t) ;
    for(auto i:a)
    {
        for(auto j:i)
        cout<<j<<" ";

        cout<<endl;
    }

}
