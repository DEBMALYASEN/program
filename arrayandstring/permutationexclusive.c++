#include<bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2)
   {
       vector<int> goal(26),curr(26),res;
       for(char i:s1)
           goal[i-'a']++;


       for(int i=0;i<s2.size();i++)
       {
           curr[s2[i]-'a']++;
           if(i>=s1.size())
               curr[s2[i-s1.size()]-'a']--;
           if(curr==goal)
               return true;
       }
       return false;

   }
   int main()
   {
       string a="bac";
       string b="docab";
       cout<<checkInclusion(a,b);
   }
