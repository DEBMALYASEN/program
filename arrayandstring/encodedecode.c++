#include<bits/stdc++.h>
using namespace std;
   string encode(vector<string> strs)
   {
       string ret = "";

       for(int i = 0; i < strs.size(); i++)
        {
           for(int j = 0; j < strs[i].size(); j++)
            {
               if(strs[i][j] == ':')
                   ret = ret + ':';
               ret = ret + strs[i][j];
           }
           ret = ret + ':';
       }
       return ret.substr(0, ret.size() - 1);
   }




   vector<string> decode(string &str)
   {

       vector<string> ret;

       string s;
       for(int i = 0; i < str.size(); i++)
       {
           if(str[i] != ':')
               s = s + str[i];
            else
            {
               if(i + 1 < str.size() && str[i + 1] == ':')
               {
                   s = s + ':';
                   i=i+2;
               }
               else
               {
                   ret.push_back(s);
                   s = "";
               }
           }
       }
       ret.push_back(s);
       return ret;
   }


   int main()
   {
       vector<string>s={"hello", "world", "::", "challenge"};
       string encod=encode(s);
       cout<<encod;//hello:world::::challenge
       cout<<endl;
       vector<string>decod=decode(encod);
       for(auto i:decod)
       cout<<i<<" ";
   }
