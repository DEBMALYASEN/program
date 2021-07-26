#include <bits/stdc++.h>
using namespace std;

void printCombinations(int i, int n, vector<int> &out)
{

    if (n == 0)
        {
            for (int i: out)
            {
                cout << i << " ";
            }
            cout << endl;
        }


    for (int j = i; j <= n; j++)
    {
        out.push_back(j);


        printCombinations(j, n - j, out);
 
        out.pop_back();
    }
}

int main()
{
    int n = 5;

    vector<int> out;

    printCombinations(1, n, out);

    return 0;
}
