#include<bits/stdc++.h>
using namespace std;
int calculate(vector<int>a)
{

    unordered_map<int,int>count;

    for(int i = 0; i < a.size(); i++)
        count[a[i]] += 1;

    int output = 0;
    for(auto i:count)
    {
        output = output + (i.second) * (i.second - 1) ;
    }
    return output/2;
}
int main()
{
    vector<int>a= {2, 2,3 };

    cout <<"XOR Pairs are : "<< calculate(a);
    return 0;
}
