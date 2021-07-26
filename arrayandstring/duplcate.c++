#include<bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int>& a)
{
        vector<int> res;
        for(int i = 0; i < a.size(); i ++)
        {
            a[abs(a[i])-1] = -a[abs(a[i])-1];
            if(a[abs(a[i])-1] > 0)
                res.push_back(abs(a [i]));
        }
        return res;
}
int main()
{

    vector<int>a={4,3,2,7,8,2,3,1};
    vector<int>res=findDuplicates(a);
    for(auto i:res)
    cout<<i;
}
