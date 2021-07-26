
#include<bits/stdc++.h>
using namespace std;

bool isProduct(int a[], int n, int x)
{
    if (n < 2)
        return false;

    unordered_set<int> s;


    for (int i=0; i<n; i++)
    {

        if (a[i] == 0)
        {
           if (x == 0)
               return true;
           else
               continue;
        }


        if (x%a[i] == 0)
        {
            if (s.find(x/a[i]) != s.end())
               return true;


            s.insert(a[i]);
        }
    }
    return false;
}

int main()
{
    int a[] = {10, 20, 9, 40};
    int x = 400;

    isProduct(a, 4, x)? cout << "Yes\n": cout << "Non";

    x = 190;
    isProduct(a, 4, x)? cout << "Yes\n": cout << "Non";

    return 0;
}
