#include<bits/stdc++.h>
using namespace std;
int countWays(int n)
{

    if (n == 1)
        return 4;  /* S _ , _S,_ _,S S */

    int countB=1, countS=1, prev_countB, prev_countS;

    for (int i=2; i<=n; i++)
    {
        prev_countB = countB;
        prev_countS = countS;

        countS = prev_countB + prev_countS;//s can be after s and b
        countB = prev_countS;// can be after s only
    }

    int result = countS + countB;

    return (result*result);//both sides
}

int main()
{
    int n ;
    cin>>n;
    cout << "Count of ways for " << n<< " sections is " << countWays(n);
    return 0;
}
