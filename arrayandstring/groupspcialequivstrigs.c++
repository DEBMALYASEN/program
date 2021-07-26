#include<bits/stdc++.h>
using namespace std;

int numSpecialEquivGroups(vector<string>& A)
{
    unordered_set<string> s;
    for (const auto& w : A)
    {
        string odd, even;
        for (int i = 0; i < w.size (); ++i)
        {
            if (i % 2)
                even  += w[i];
            else
                odd += w[i];
        }
        sort (even.begin (), even.end());
        sort (odd.begin(), odd.end());
        s.insert(even +  odd);
    }
    return s.size ();
}

int main()
{
    vector<string>a={"abcd","cdab","cbad","xyzz","zzxy","zzyx"};
    cout<<numSpecialEquivGroups(a);

}
