#include<bits/stdc++.h>
using namespace std;
string addStrings(string num1, string num2)
 {
        string ans = " ";
        int carry = 0;

        int l1 = num1.size() - 1;
        int l2 = num2.size() - 1;

        while(l1 >= 0 || l2 >= 0 || carry)
         {
            int n1 = l1 >= 0 ? num1[l1] - '0' : 0;
            int n2 = l2 >= 0 ? num2[l2] - '0' : 0;
            int s = n1 + n2 + carry;
            char v = '0' + (s % 10);
            carry = (s >= 10) ? 1 : 0;
            ans = v + ans;
            l1--;
            l2--;
        }
        return ans;
    }
