
#include <bits/stdc++.h>
using namespace std;
long countWays(int n, int k) //n post k colors
{

  //first post
    int same = k*1, diff = k*(k-1);
    int total=same+diff;
 //atmost 2 fences can have same color
    for (int i = 3; i <= n; i++)
     {
        same = diff*1;// same when last 2 are same .diff last 2 are different

        diff = total * (k - 1);

        total = (same + diff) ;
    }

    return total;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<countWays(n,k);
}
