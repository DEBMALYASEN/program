#include<bits/stdc++.h>
using namespace std;
string shiftingLetters(string S, vector<int>& shifts)
    {

        for (int i = shifts.size() - 2; i >= 0; i--)
            shifts[i] = (shifts[i] + shifts[i+1]) % 26;



        for (int i = 0; i < shifts.size(); i++)
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';


        return S;
    }
int main()
{
    string s="aaa";
    vector<int>shift={1,2,3};
    cout<<shiftingLetters(s,shift);
}
