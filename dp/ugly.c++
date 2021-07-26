#include<bits/stdc++.h>
using namespace std;
int nthugly(int n)
{

 int dp[100];
 int p2 = 0, p3 = 0, p5 = 0;
 int next_ugly;

    dp[0] = 1;

    for (int i=1; i<n; i++)
    {
		next_ugly = min(dp[p2] * 2,min( dp[p3] * 3, dp[p5] * 5));
		dp[i] = next_ugly;
		if (next_ugly == dp[p2]*2)
			p2 = p2+1;
		if(next_ugly == dp[p3]*3)
			p3 = p3+1;
		if(next_ugly == dp[p5]*5)
			p5 = p5+1;
    }
    return next_ugly;
}

int main()
{
    int n;
    cin>>n;
    cout<<nthugly(n);
}
