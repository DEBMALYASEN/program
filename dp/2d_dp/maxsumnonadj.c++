#include<bits/stdc++.h>
using namespace std;
int maxsumnonadj(int a[100],int n)
{
    int inc=a[0];
    int exc=0;
    for(int i=1;i<n;i++)
    {
        int ninc=exc+a[i];
        int nexc=max(inc,exc);

        inc=ninc;
        exc=nexc;
    }
    int ans=max(inc,exc);
    return ans;
}
int main()
{
    int a[100]={5,10,15,-10,20};
    cout<<maxsumnonadj(a,5);
}
