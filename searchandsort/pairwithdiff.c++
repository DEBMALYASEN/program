#include <bits/stdc++.h>
using namespace std;

bool findPair(int a[], int size, int diff)
{

    int i = 0;
    int j = 1;


    while (i < size && j < size)
    {
        if (i != j && a[j] - a[i] == diff)
        {
            cout << "Pair Found: (" << a[i] <<", " << a[j] << ")";
            return true;
        }
        else if (a[j]-a[i] < diff) 
            j++;
        else
            i++;
    }

    cout << "No such pair";
    return false;
}

int main()
{
    int a[] = {1, 8, 30, 40, 100};
    int diff = 60;
    findPair(a, 5, diff);
    return 0;
}
