#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p=1,c=0;;
    cin>>n;
    while(n>9)
    {
        p=1;
        while(n)
        {
            p=p*(n%10);
            n=n/10;
        }
        //cout<<p<<" ";
        n=p;
        c++;
    }
    cout<<c;
}
