#include<bits/stdc++.h>
using namespace std;

struct dolls
{
    int width, height;
};

bool compare(struct dolls a, struct dolls b)
{

    return a.width< b.width;
}

int maxdolls(struct dolls values[], int n)
{
    int lis[n];
    for (int i=0; i<n; i++)
        lis[i] = 1;

 sort(values, values+n, compare);

    for (int i=1; i<n; i++)
        for (int j=0; j<i; j++)
            if (values[i].height > values[j].height && lis[i] < 1 + lis[j] && values[i].width > values[j].width)
                lis[i] = 1 + lis[j];


    int max = lis[0];
    for (int i=1; i<n; i++)
        if (max < lis[i])
            max = lis[i];

    return max;
}

int main()
{
    struct dolls values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
    int n = 4;
    cout << "Maximum number of dolls = " << maxdolls(values, n);
    return 0;
}
