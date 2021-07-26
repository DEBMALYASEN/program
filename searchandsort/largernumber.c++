#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
        return a+b > b+a;
}
    string largestNumber(vector<int>& nums)
    {
        vector<string> strcontain;
        for(int i : nums)
         strcontain.push_back(to_string(i));

        sort(strcontain.begin(),strcontain.end(),cmp);

        string result;
        for(int i=0;i<strcontain.size();i++)
        result+=strcontain[i];

        return result[0]=='0'? "0" : result;
    }
    int main()
    {
        vector<int>a={3,32};
        cout<<largestNumber(a);
    }
