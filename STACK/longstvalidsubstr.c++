#include <bits/stdc++.h>
using namespace std;
int findMaxLen(string s)
{
    int n = s.length();
    stack<int> stack;
    stack.push(-1);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            stack.push(i);//stror index of prev starting brac in stack

        else              /*     ((()()                        -1((       3-1=2     1(((   -1((    */
        {
            if (!stack.empty())
                stack.pop();

            if (!stack.empty())
                result = max(result, i - stack.top());

            else
                stack.push(i);
        }
    }

    return result;
}
int main()
{
    string str = "((()()";

    cout << findMaxLen(str) << endl;

    str = "()(()))))";

    cout << findMaxLen(str) << endl;

    return 0;
}
