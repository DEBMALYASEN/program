#include<bits/stdc++.h>
using namespace std;
int strings_no_consecutive(int n)
{
    int dp[1000];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2];
    return dp[n]+dp[n-1];
}
// n=3 000 001 010  100 101 (END WITH 0(3)+END WITH 1(2)) ans =5
// n=2 00 01 10 (END WITH 0(2)+END WITH 1(1))ans=3
//n=1 0 1 ans=2
int main()
{
    int n;
    cin>>n;
    for(n=0;n<=10;n++)
    cout<<strings_no_consecutive(n)<<endl;//binary string no consecutive 1
}
