#include <bits/stdc++.h>
using namespace std;

int distinctCount(vector<int>a)//sorted
{
    int count = a.size();

    int i = 0, j = a.size() - 1, sum = 0;

    while (i < j)
    {
        while (i != j && a[i] == a[i + 1])
            count--, i++;

        while (i != j && a[j] == a[j - 1])
            count--, j--;


        if (i == j)
            break;


        sum = a[i] + a[j];

        if (sum == 0)
        {
            count--;
            i++, j--;
        }
        else if(sum < 0)
            i++;
        else
            j--;
    }

    return count;
}

int main()//-2 -1 0  1
{
    vector<int>a={-2, -1, 0, 1, 1};
    cout << "Count of absolute distinct values : " << distinctCount(a);
    return 0;
}
