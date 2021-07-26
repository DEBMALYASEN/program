#include<bits/stdc++.h>
using namespace std;
void lislength(int a[],int n)
{
    int dp[100];
    dp[0]=1;
    int j=0,i=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            dp[i]=dp[j]+1;
        }
    }
    for(i=0;i< n;i++)
    cout<<dp[i]<<" ";
}
int main()
{
    int a[]={2,5,6,9,7,8,9};
     lislength(a,7);
}
