#include<bits/stdc++.h>
using namespace std;
string optimalDivision(vector<int>& nums)
 {
        string s = "";
        for(int i:nums)
            s += to_string(i) + "/";
        if(nums.size()<3) {
            s.erase(s.size()-1);
            return s;
        }
        s[s.size()-1] = ')';
        s.insert(s.find("/")+1, "(");
        return s;
    }
    int main()
    {
        vector<int>A={5,6,7,2};
        cout<<optimalDivision(A);
    }
