#include<bits/stdc++.h>
using namespace std;

int floorCrt(int x)
{
    if (x == 0 || x == 1)
    return x;
    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (mid*mid*mid == x)
            return mid;

        if (mid*mid*mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid-1;
    }
    return ans;
}


int main()
{
    int x;
    cin>>x;
    for(int i=1;i<=x;i++)
    cout << floorCrt(i) << endl;
    return 0;
}
