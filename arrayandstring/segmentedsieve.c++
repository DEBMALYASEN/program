#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
void sieve(int n)
{
    vector<bool>isprime((n+1),true);
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            for(int j=i*i;j<=n;j=j+i)
            isprime[i]=false;

        }
    }
}
void segsieve(int l,int h)
{
    int sq=sqrt(h);
    sieve(sq);
    vector<bool>isprime(h-l+1,true);
    for(auto i:prime)
    {
        int sm=(l/i)*i;
        if(sm<l)
        sm=sm+i;
        for(int j=sm;j<=h;j=j+i)
        isprime[j-l]=false;

    }
    for(int i=l;i<=h;i++)
    {
        if(isprime[i-l])
        cout<<i<<" ";
    }

}
int main()
{
    int l,h;
cin>>l>>h;
    segsieve(l,h);
}
