
#include <bits/stdc++.h>
using namespace std;


string secMostRepeated(vector<string> seq)
{

    unordered_map<string, int> occ;
    for (int i = 0; i < seq.size(); i++)
        occ[seq[i]]++;
  
    int first_max = INT_MIN, sec_max = INT_MIN;
    for (auto it = occ.begin(); it != occ.end(); it++) {
        if (it->second > first_max) {
            sec_max = first_max;
            first_max = it->second;
        }

        else if (it->second > sec_max &&
                 it->second != first_max)
            sec_max = it->second;
    }


    for (auto it = occ.begin(); it != occ.end(); it++)
        if (it->second == sec_max)
            return it->first;
}


int main()
{
    vector<string> seq = { "ccc", "aaa", "ccc",
                          "ddd", "aaa", "aaa" };
    cout << secMostRepeated(seq);
    return 0;
}
