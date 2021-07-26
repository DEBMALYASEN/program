#include<bits/stdc++.h>
using namespace std;
string multiply(string a, string b)
{
        int i,j;
        if(a=="0"||b=="0")
            return "0";
        vector<int> res(a.size()+b.size(),0);


        for(i=a.size()-1;i>=0;i--)
        {
            for(j=b.size()-1;j>=0;j--)
            {
                res[i+j+1]+=((a[i]-'0')*(b[j]-'0'));
                res[i+j]+=(res[i+j+1]/10);
                res[i+j+1]%=10;
            }
        }
        i=0;
        while(i<res.size() && res[i]==0)
        i++;
        string ans="";
        while(i<res.size())
            ans+=(res[i++]+'0');
        return ans;
}
int main()
{
    string a="100";
    string b="99";
    cout<<multiply(a,b);
}
