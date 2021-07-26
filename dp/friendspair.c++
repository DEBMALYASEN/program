#include<bits/stdc++.h>
using namespace std;
int friendspair(int n)
{
    int dp[1000];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    dp[i]=dp[i-1]+(i-1)*dp[i-2];
    return dp[n];
}
// Consider N friends
// now 2 cases
// 1  person n-1 persons
// 2 persons(here 2nd person is among n-1 person) n-2 persons
int main()
{
    int n;
    cin>>n;
    cout<<friendspair(10);
}
