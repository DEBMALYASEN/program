#include<bits/stdc++.h>
using namespace std;

class Stack
{
    stack<int> s;
    int min;

public:

    void push(int x)
    {
        if (s.empty())
        {
            s.push(x);
            min = x;
        }
        else if (x > min)
            s.push(x);

        else
        {
            s.push(2*x - min);
            min = x;
        }
    }

    void pop()
    {
        if (s.empty())
            cout << "Stack underflow!!" << endl;

        int top = s.top();
        if (top < min)
            min = 2*min - top;

        s.pop();
    }

    int minimum()
    {
        return min;
    }
};

int main()
{
    Stack s;

    s.push(6);
    cout << s.minimum() << endl;

    s.push(7);
    cout << s.minimum() << endl;

    s.push(5);
    cout << s.minimum() << endl;

    s.push(3);
    cout << s.minimum() << endl;

    s.pop();
    cout << s.minimum() << endl;

    s.pop();
    cout << s.minimum() << endl;

    return 0;
}
