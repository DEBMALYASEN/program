#include <bits/stdc++.h>
using namespace std;

int find_consecutive_steps(int a[], int len)
{
    int count = 0;
    int maximum = 0;

    for (int index = 1; index < len; index++)
     {

        if (a[index] > a[index - 1])
            count++;
        else
        {
            maximum = max(maximum, count);
            count = 0;
        }
    }

    return max(maximum, count);
}

int main()
{
    int a[] = { 1, 2, 3, 4 };

    cout << find_consecutive_steps(a, 4);
}
