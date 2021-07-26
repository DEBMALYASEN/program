
#include <bits/stdc++.h>
using namespace std;

//won't work for all deno
int deno[] = { 1, 2, 5, 10, 20,50, 100, 500, 1000 };
int n=9;

void findMin(int V)
{
    sort(deno, deno + n);

    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {

        while (V >= deno[i])
         {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    int n = 93;
    findMin(n);
    return 0;
}
