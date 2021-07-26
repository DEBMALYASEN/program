#include<bits/stdc++.h>
using namespace std;
int evalRPN(string  t)
  {
       stack<int> s;
       int a,b;
       for(auto x : t)
       {
           if(x=='+')
           {
               b=s.top();s.pop();
               a=s.top();s.pop();
               s.push(a+b);
           }
           else if(x=='-')
           {
               b=s.top();s.pop();
               a=s.top();s.pop();
               s.push(a-b);
           }
           else if(x=='*')
           {
               b=s.top();s.pop();
               a=s.top();s.pop();
               s.push(a*b);
           }
           else if(x=='/')
           {
               b=s.top();s.pop();
               a=s.top();s.pop();
               s.push(a/b);
           }
           else
           s.push(x-'0');
       }
       return s.top();
   }
   int main()
   {
      string s="23+9-";
      cout<<evalRPN(s);
   }
