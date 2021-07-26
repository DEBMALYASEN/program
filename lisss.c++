#include<bits/stdc++.h>
using namespace std;

int LIS(int n, vector<int> &v){

	vector<int> dp(n+1,0);

	dp[0] = 1;
	if(n >=2)
		dp[1] = v[0] > v[1] ? 1 : 2;

	for(int i = 2; i < n ; i++){

		int op1 = dp[i-1];
		if(v[i] > v[i-1]){
			op1 = dp[i-1] + 1;
		}
		dp[i] = max(dp[i-1],op1);
	}

	for(auto it  : dp){
		cout << it << " ";
	}
	cout << endl;
	return dp[n-1];
}
int main()
{
    vector<int>v={0,1,99,100,-1,2,3,4};
    cout<<LIS(v.size(),v);
}
