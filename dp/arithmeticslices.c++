#include<bits/stdc++.h>
using namespace std;
int arithmeticslices(int a[100],int n)
{
    int dp[100],ans=0;
    for(int i=2;i<n;i++)
    {
        if(a[i]-a[i-1]==a[i-1]-a[i-2])
        dp[i]=dp[i-1]+1;
        ans+=dp[i];
    }
    return ans;
}
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<arithmeticslices(a,n);

}
