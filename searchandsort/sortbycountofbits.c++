
#include <bits/stdc++.h>

using namespace std;


int countBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}

int cmp(int a, int b)
{
    int count1 = countBits(a);
    int count2 = countBits(b);

    return count1 >count2;

}

void sortBySetBitCount(vector<int>&a)
{
    stable_sort(begin(a), end(a), cmp);
}

int main()
{
    vector<int>a= {5, 2, 3, 9, 4, 6, 7, 15, 32};

    sortBySetBitCount(a);

    for(auto i:a)
    cout<<i<<" ";
    return 0;
}
