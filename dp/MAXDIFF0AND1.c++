#include<bits/stdc++.h>
using namespace std;
int c(string s)
{
   int ans=0,csum=0;
    for(int i=0;i<s.size();i++)
    {
    int val=0;
    if(s[i]=='0')
    val=1;
    else
    val=-1;
    if(csum>0)
        csum+=val;
    else
        csum=val;
    if(csum>ans)
    ans=csum;
}
return ans==0?-1:ans;
}
int main()
{
    string s="1100100";
    cout<<c(s);
}
