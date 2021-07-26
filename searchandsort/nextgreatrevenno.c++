#include<bits/stdc++.h>
using namespace std;
int main()
{

        string s;
        cin>>s;
        int l=s.length();
        bool flag=false;

        while(next_permutation(s.begin(),s.end()))
        {
        if((s[l-1]-'0')%2==0)
        {
            flag=true;
            break;
        }

        }
        if(!flag)
        cout<<"-1"<<endl;
        else
        cout<<s<<endl;
        
}
