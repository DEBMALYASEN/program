#include<bits/stdc++.h>
using namespace std;
int longestPalindrome(string s)

{
unordered_map<char,int> m ;

    for(int i=0;i<s.length();i++)
    m[s[i]]++ ;
    int count = 0,d =0;
    for(auto x:m)
    {
        if(x.second%2 == 0)
            count += x.second ;
        else
        {
            if(x.second > 2)
                  count += x.second-1 ;
            d++;
        }
    }
    if(d > 0)
    return count+1 ;

    return count ;
}
int main()
{
    string s="aaabbc";
    cout<<longestPalindrome(s);
}
