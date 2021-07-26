#include <bits/stdc++.h>
using namespace std;
bool canFormPalindrome(string str)
{
    map<int,int>count;
    for (int i = 0; str[i]; i++)
        count[str[i]]++;

    int odd = 0;
    for (auto i:count)
        {
            if (i.second & 1)
            {
            odd++;
          }
        if (odd > 1)
            return false;
    }

    return true;
}

int main()
{
    canFormPalindrome("geeksforgeeks")
      ? cout << "Yes\n"
      : cout << "No\n";
    canFormPalindrome("geeksogeeks")
      ? cout << "Yes\n"
      : cout << "No\n";
    return 0;
}
