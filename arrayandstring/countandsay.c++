#include<bits/stdc++.h>
using namespace std;

    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string res;
        string temp = countAndSay(n-1);

        char ele = temp[0];
        int count = 1;

        for (int i = 1; i <= temp.size(); i++)
        {
            if (temp[i] == ele)
                count++;
             else
            {
                res += to_string(count);
                res.push_back(ele);
                ele = temp[i];
                count = 1;
            }
        }

        return res;
    }
    int main()
    {
        int n;
        cin>>n;
        cout<<countAndSay(n);
    }
