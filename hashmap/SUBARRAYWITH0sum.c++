#include <bits/stdc++.h>
using namespace std;

bool hasZeroSumSubarray(int A[], int n)
{
    unordered_set<int> set;

    set.insert(0);

    int sum = 0;


    for (int i = 0; i < n; i++)
    {

        sum += A[i];

        if (set.find(sum) != set.end())
            return true;
        else

            set.insert(sum);
        }
    

    return false;
}

int main()
{
    int A[] = { 4, 2, -3, -1, 0, 4 };
    int n = sizeof(A)/sizeof(A[0]);

    hasZeroSumSubarray(A, n) ?cout << "Subarray exists":cout << "Subarray does not exist";

    return 0;
}
