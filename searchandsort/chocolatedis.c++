#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int>chocolates,int students)
{

    if (chocolates.size() == 0 || students == 0)
        return 0;

    sort(begin(chocolates),end(chocolates));

    if (chocolates.size()<students)
        return -1;


    int min_diff = INT_MAX;


    for (int i = 0; i + students - 1 < chocolates.size(); i++)
    {
        int diff = chocolates[i + students - 1] - chocolates[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main()
{   vector<int>chocolates={7, 3, 2, 4, 9, 12, 56};
    int student =3;
    cout << "Minimum difference is "<< findMinDiff(chocolates,student);
    return 0;
}
