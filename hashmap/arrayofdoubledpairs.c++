#include<bits/stdc++.h>
using namespace std;
bool comp(int a ,int b)
{
    return abs(a)<abs(b);
}
bool  canbereordered(vector<int>a,int n)
{
    unordered_map<int,int>map;
    for(int i:a)
    map[i]++;

    sort(begin(a),end(a),comp);
    for(int i:a)
    {
     if(map[i]==0)
     continue;


      if(map[2*i]<1)
      return false;

      map[i]--;
      map[2*i]--;
    }
    return true;
}
int main()
{
    vector<int>a={-4,2,-2,4};
    cout<<canbereordered(a,4);
}
