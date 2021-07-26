#include <bits/stdc++.h>
using namespace std;

void rearrange(vector<int>&a, int x)
{

    stable_sort(begin(a),end(a), [x](int a, int b)
    {
        if (abs(a - x) < abs(b - x))
            return true;
        else
            return false;
    });
}

int main()
{
    vector<int> a={ 10, 5, 3, 9, 2 };

    int x = 0;
    rearrange(a, x);
    for (auto i:a)
        cout << i << " ";
    return 0;
}
