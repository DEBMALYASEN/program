#include<bits/stdc++.h>
using namespace std;
bool ispalin(string s)
{
    int l=0;
    int h=s.size()-1;
    while(l<h)
    {
        if(s[l]!=s[h])
        return 0;
        l++;
        h--;
    }
    return 1;
}

int main()
{

        string s;
        cin>>s;
        int l=s.length();
        bool flag=false;

        while(next_permutation(s.begin(),s.end()))
        {
        if(ispalin(s))
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
