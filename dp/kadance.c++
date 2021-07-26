#include<bits/stdc++.h>
using namespace std;
int maxSumsubarray(int a[],int n)
{
    int cur_sum=0;
    int max_so_far=0;
    for(int i=0;i<n;i++)
    {
        cur_sum+=a[i];
        if (cur_sum <0)
        cur_sum=0;
        max_so_far=max(max_so_far,cur_sum);
    }
    return max_so_far;
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<maxSumsubarray(a,n);
}
