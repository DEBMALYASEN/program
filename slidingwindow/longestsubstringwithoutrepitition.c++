#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string s)
{
    map<char, int> seen ;
    int maximum_length = 0;
    int start = 0;

    for(int end = 0; end < s.length(); end++)
    {

        if (seen.find(s[end]) != seen.end())
            start = max(start, seen[s[end]] + 1);

        seen[s[end]] = end;
        maximum_length = max(maximum_length, end - start + 1);
    }
    return maximum_length;
}


int main()
{
    string s = "geeksforgeeks";
    cout << "The input String is " << s << endl;
    int length = longestUniqueSubsttr(s);

    cout<<"The length of the longest non-repeating character "
        <<"substring is "
        << length;
}
