#include <bits/stdc++.h>
using namespace std;

int countBuildings(vector<int>a)
{

    int count = 1;


    int curr_max = a[0];

    for (int i = 1; i < a.size(); i++)
    {

        if (a[i] > curr_max || a[i] == curr_max)
        {
            count++;
            curr_max = a[i];
        }
    }

    return count;
}

int main()
{

   vector<int>a={ 7, 4, 8, 2, 9 };
    cout << countBuildings(a);
    return 0;
}
