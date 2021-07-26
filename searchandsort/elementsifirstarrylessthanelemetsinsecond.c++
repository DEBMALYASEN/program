#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int>b, int x)
{
    int l=0;
    int h=b.size()-1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (b[mid] <= x)
            l = mid + 1;
        else
            h = mid - 1;
    }

    return h;
}

void countEleLessThanOrEqual(vector<int>a, vector<int>b)
{

    sort(begin(b),end(b));//0 1 1 1  2 4

    for (int i = 0; i < a.size(); i++)
    {
        int index = binary_search(b ,a[i]);
        cout << (index + 1) << " ";
    }
}


int main()
{
    vector<int>a =  { 1, 2, 3, 4, 7, 9 };
    vector<int>b = { 0, 1, 2, 1, 1, 4 };

    countEleLessThanOrEqual(a,b);//4 5 5 6 6 6
    return 0;
}
