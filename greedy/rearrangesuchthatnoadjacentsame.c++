#include<bits/stdc++.h>
using namespace std;
void rearrange(string s)
{
    map<char,int>m;
    for(auto i:s)
        m[i]++;
    int maximum=0;
    char max_char;




    for(auto i:m)
    {
          if(i.second>maximum)
            {
                maximum=max(maximum,i.second);
                max_char=i.first;
            }

    }


    char res[s.size()];
    int i=0;


   while(maximum>0)
    {
        res[i]=max_char;
        i=i+2;
        maximum=maximum-1;
    }



    m[max_char]=0;


    int t=1;
    for(auto i:m)
    {
      while(i.second--)
        {
            res[t]=i.first;
            t=t+2;
        }
    }

    for(auto i: res)
    cout<<i;

}

int main()
{
    string s="bbaa";
    rearrange(s);
}
