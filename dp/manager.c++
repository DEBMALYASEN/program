#include <bits/stdc++.h>
using namespace std;

vector<char>  findAllReportingEmployees(char m,unordered_map<char, vector<char>> &mTe,unordered_map<char, vector<char>> &result)
{
    if (result.find(m) != result.end())
        return result[m];



    vector<char> managerEmployees = mTe[m];

    for (char r: mTe[m])
    {
        vector<char> es = findAllReportingEmployees(r,mTe, result);

        move(e.begin(),e.end(),back_inserter(managerEmployees));
    }

    result[m] = managerEmployees;

    return managerEmployees;
}

void findEmployees(unordered_map<char, char> &eTm)
{

    unordered_map<char, vector<char>> mTe;

    for (auto i: eTm)
    {
        char e =i.first;
        char m =i.second;

        if (e != m)
            mTe[m].push_back(e);

    }

    unordered_map<char, vector<char>> result;


    for (auto p: eTm)
        findAllReportingEmployees(p.first, mTe, result);


    for (auto p: result)
    {
        cout << p.first << " —> ";
        for (auto i: p.second)
            cout << i << " ";
        cout << endl;
    }
}



int main()
{
    unordered_map<char, char> eTm =
    {
        {'A', 'A'},
        {'B', 'A'},
        {'C', 'B'},
        {'D', 'B'},
        {'E', 'D'},
        {'F', 'E'}
    };

    findEmployees(eTm);

    return 0;
}
