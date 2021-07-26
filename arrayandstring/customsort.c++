#include<bits/stdc++.h>
using namespace std;
string customSortString(string S, string T)
{
        sort(T.begin(), T.end(),[&](char a, char b) { return S.find(a) < S.find(b); });
        return T;
}
int main()
{
    string order,s;
    order="cba";
    s="adbc";
    cout<<customSortString(order,s);
}
