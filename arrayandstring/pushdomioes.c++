#include<bits/stdc++.h>
using namespace std;
string pushDominoes(string s)
{

    int n=s.length();
    vector<int>pref,suff;
    pref.assign(n,0); suff.assign(n,0);
    int curr=INT_MAX;
    for(int i=0;i<n;i++)//dis to imm right from left
    {
        pref[i]=curr;
        if(s[i]=='R')
         curr=0;
        if(s[i]=='L')
         curr=INT_MAX;
        if(s[i]=='.'&&curr!=INT_MAX)
        curr++;
    }
    curr=INT_MAX;
    for(int i=n-1;i>=0;i--)//dis to imm left from right
    {
        suff[i]=curr;
        if(s[i]=='L')
        curr=0;
        if(s[i]=='R')
        curr=INT_MAX;
        if(s[i]=='.'&&curr!=INT_MAX)
        curr++;
    }



    string ans;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        ans.push_back('L');
        else if(s[i]=='R')
        ans.push_back('R');
        else
        {
            if(pref[i]<suff[i])
            ans.push_back('R');
            else if(pref[i]>suff[i])
            ans.push_back('L');
            else
             ans.push_back('.');
        }
    }

    return ans;
}
int main()
{
    string s=".L.R...LR..L..";
    cout<<pushDominoes(s);
}
