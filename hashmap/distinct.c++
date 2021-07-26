#include<bits/stdc++.h>
using namespace std;
unordered_set<int> distint(vector<vector<int>>v)
{

    unordered_set<int>s,res;
    int i,j;
    for(int i=0;i<v[0].size();i++)
    s.insert(v[0][i]);

    for(i=1;i<v.size();i++)
    {
     unordered_set<int>t;
        for(j=0;j<v[i].size();j++)
            t.insert(v[i][j]);

        for(auto i=s.begin();i!=s.end();i++)
        {
            if(t.find(*i)==t.end())
            s.erase(*i);
        }

          t.clear();
    }
return s;

}
int main()
{

    vector<vector<int>>v={{1,2,3},{4,2,3},{7,8,3}};
    unordered_set<int> k=distint(v);
    for(auto i:k)
    cout<<i<<" ";

}
