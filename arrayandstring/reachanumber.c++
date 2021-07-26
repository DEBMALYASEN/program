#include<bits/stdc++.h>
using namespace std;
int reachNumber(int target)
{
	target = abs(target);
	if (target == 0)
		return 0;

	int count = 0, step = 0;
	while (true)
    {
		count++;
		step += count;
		if (step == target || step > target && (step - target) % 2 == 0)
			return count;
	}
	return 0;
}
int main()
{   int n;
    cin>>n;
    cout<<reachNumber(n);
}
