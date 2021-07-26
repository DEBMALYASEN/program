
#include <bits/stdc++.h>
using namespace std;
int maximum(int a, int b, int c)
{
   return max(max(a, b), c);
}

int minimum(int a, int b, int c)
{
   return min(min(a, b), c);
}

void smallestDifferenceTriplet(vector<int>a,vector<int>b,vector<int>c)
{

    sort(begin(a), end(a));
    sort(begin(b), end(b));
    sort(begin(c), end(c));


    int res_min, res_max, res_mid;

    int i = 0, j = 0, k = 0;

    int diff = INT_MAX;
    int n=a.size();

    while (i < n && j < n && k < n)
    {
        int sum = a[i] + b[j] + c[k];

        int max = maximum(a[i], b[j], c[k]);

        int min = minimum(a[i], b[j], c[k]);


        if (min == a[i])
            i++;
        else if (min == b[j])
            j++;
        else
            k++;


        if (diff > (max-min))
        {
            diff = max - min;
            res_max = max;
            res_mid = sum - (max + min);
            res_min = min;
        }
    }

    cout << res_max << ", " << res_mid << ", " << res_min;
}

int main()
{
vector<int>a = {5, 2, 8};
vector<int>b = {10, 7, 12};
vector<int>c = {9, 14, 6};

smallestDifferenceTriplet(a, b, c);
    return 0;
}
