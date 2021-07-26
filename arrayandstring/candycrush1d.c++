#include<bits/stdc++.h>
using namespace std;
string candy1d(string s)
{



    stack<pair<char,int>> stack;

    stack.push(make_pair(s[0],1));

    for(int i=1;i<s.size();i++)
    {
         char top=stack.top().first;
         int  freq=stack.top().second;
         if(s[i]==top)
         {
             stack.pop();
             if(freq<2)
             stack.push(make_pair(s[i],freq+1));
         }
         else
         stack.push(make_pair(s[i],1));
    }


    string w=" ";
    while(!stack.empty())
    {
        char top=stack.top().first;
        int freq=stack.top().second;
        while(freq--)
            w=w+top;

        stack.pop();
    }
    reverse(begin(w),end(w));
    return w;


}
int main()
{
    string s="aaabbbacd";
    cout<<candy1d(s);
}
