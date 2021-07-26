#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > findSubArrays(int a[], int n)
{
    unordered_map<int, vector<int> > map;
    vector <pair<int, int>> out;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {

        sum += a[i];

        if (sum == 0)
            out.push_back(make_pair(0, i));


        if (map.find(sum) != map.end())
        {

            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        map[sum].push_back(i);
    }

    return out;
}

int main()
{
    int a[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};


    vector<pair<int, int> > out = findSubArrays(a, 11);

    for(auto i: out)
    cout << "Subarray found from Index " << i.first << " to " << i.second << endl;

    return 0;
}
