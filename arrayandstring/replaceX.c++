#include <bits/stdc++.h>
using namespace std;

void replacePattern(string s,string p)
{

    int len =p.size();

    if (len == 0)
        return;
auto i=s.begin();
while(i!=s.end())
{
    i=search(s.begin(), s.end(), p.begin(), p.end());
    if(i!=s.end())
    {
    s.erase(i,i+p.size());
    s.insert(i,'X');
}
}
cout<<s<<endl;
for(int i=0;i<s.size()-1;i++)
{
    if(s[i]=='X' && s[i+1]=='X')
    {
        s.erase(s.begin()+i);
         i--;
     }

}
cout<<s;
}

int main()
{
 string s = " GeeksGeeksforGeeks";
 string p = "Geeks";

replacePattern(s, p);


    return 0;
}
