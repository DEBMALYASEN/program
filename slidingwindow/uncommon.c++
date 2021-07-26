#include<bits/stdc++.h>
using namespace std;
string uncommon(string a,string b)
{
    unordered_map<char,int>m;
    for(auto i:a)
    m[i]=1;
    for(auto i:b)
    {
        if(m[i]==1)
        m[i]=-1;
        else
        m[i]=2;
    }
    string w =" ";
    for(auto i:m)
    {
        if(i.second==1 ||i.second==2)
        w=w+i.first;
    }
    return w;
}
int main()
{
    cout<<uncommon("geeksforgeeks","geeksquiz");
}
