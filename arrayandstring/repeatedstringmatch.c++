#include<bits/stdc++.h>
using namespace std;
int repeatedStringMatch(string A, string B)
{
       string s="";
       int count = 0;
       while(s.size()<B.size())
       {
           s+=A;
           count++;
       }
       if(s.find(B)!=string::npos)
           return count;
       s+=A;
       count++;
       if(s.find(B)!=string::npos)
           return count;

       return -1;

   }
   int main()
   {
       string a="abcd";
       string b="cdabcdab";
       cout<<repeatedStringMatch(a,b);
   }
