
#include <bits/stdc++.h>
using namespace std;

int trailingZeroes(int n)
{
    int c = 0;
    while (n > 0)
     {
        n /= 5;
        c += n;
    }
    return c;
}
void binarySearch(int n)
{
    int low = 0;
    int high = 1e6;


    while (low < high)
    {
        int mid = (low + high) / 2;
        int count = trailingZeroes(mid);
        if (count < n)
            low = mid + 1;
        else
            high = mid;
    }


    vector<int> result;
    while (trailingZeroes(low) == n)
    {
        result.push_back(low);
        low++;
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}


int main()
{
    int n ;
    cin>>n;
    cout  << findTrailingZeros(n);
    return 0;
}
