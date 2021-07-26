▲#include <bits/stdc++.h>

using namespace std;

struct CityPairs
{
    int north, south;
};

bool compare(struct CityPairs a, struct CityPairs b)
{
    if (a.south == b.south)
        return a.north < b.north;
    return a.south < b.south;
}

int maxBridges(struct CityPairs values[], int n)
{
    int lis[n];
    for (int i=0; i<n; i++)
        lis[i] = 1;

    sort(values, values+n, compare);

    for (int i=1; i<n; i++)
        for (int j=0; j<i; j++)
            if (values[i].north >= values[j].north&& lis[i] < 1 + lis[j])
                lis[i] = 1 + lis[j];


    int max = lis[0];
    for (int i=1; i<n; i++)
        if (max < lis[i])
            max = lis[i];

    return max;
}

int main()
{
    struct CityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
    int n = 4;
    cout << "Maximum number of bridges = " << maxBridges(values, n);
    return 0;
}
