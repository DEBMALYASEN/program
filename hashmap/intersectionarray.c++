#include<bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> &v1, vector<int>& v2);

int main()
{
    vector<int>a={2,3,4,2,5};
    vector<int>b ={2,2,3,4};
    vector<int>v=intersection(a,b);
    for(auto i :v)
    cout<<i<<" ";

}
vector<int> intersection(vector<int> &v1, vector<int>& v2)
{

 vector<int> res,v3;


 sort(v1.begin(), v1.end());
 sort(v2.begin(), v2.end());

 set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

 set<int> s;
    for(int i = 0;i <v3.size();i++)
        s.insert(v3[i]);

    for(auto i:s)
        res.push_back(i);

    return res;
}
