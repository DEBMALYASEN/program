#include<bits/stdc++.h>
using namespace std;
vector<int> partitionLabels(string S)
{
       vector<int> res;
       unordered_map<int,int> pos;
       for (auto i = 0; i < S.size(); ++i) pos[S[i]] = i;
       int j = 0, anchor = 0;
       for(int i = 0; i < S.size(); ++i)
       {
           j = max(j, pos[S[i]]);
           if(i == j){
               res.push_back(i - anchor + 1);
               anchor = i + 1;
           }
       }
       return res;
   }
   int main()
   {
       string s="ababcbacadefegdehijhklij";
       vector<int>x=partitionLabels(s);
       for (auto i:x)
       cout<<i<<" ";
   }
