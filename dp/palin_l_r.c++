#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool dp[100][100];
    int n=s.size(),i,j;
    for(i=0;i<n;i++)
    dp[i][i]=true;
    for(int i=2;i<=n;i++)
    {
            for(j=0;j+i-1<n;j++)
            {
                int start=i;
                int end=j+i-1;
                if(i==2)
                {
                    if(s[start]==s[end])
                    dp[start][end]=true;
                    else
                    dp[start][end]=false;
                }
                else
                {
                    dp[start][end]=(s[start]==s[end])&&(dp[start+1][end-1]);
                }
            }

    }
    int t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<(dp[l][r]?"YES":"NO")<<'\n';
    }
}
