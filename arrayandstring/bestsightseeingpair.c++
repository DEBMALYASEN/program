#include<bits/stdc++.h>
using namespace std;

int maxScoreSightseeingPair(vector<int>& v)
 {
   int res=0;
   int maxi=v[0];
  for(int i=1;i<v.size();i++)
   {
   res=max(res,maxi+v[i]-i);
    maxi=max(maxi,v[i]+i);
}
return res;
}
int main()
{
    vector<int>a={8,1,5,2,6};
    cout<<maxScoreSightseeingPair(a);
}
