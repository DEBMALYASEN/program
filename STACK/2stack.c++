#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int capacity;
    int top1, top2;

public:
    Stack(int n)
    {
        capacity = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }


    void push1(int key)
    {
        if (top1 + 1 == top2)
            cout << "Stack Overflow";



        top1++;
        arr[top1] = key;
    }

    void push2(int key)
    {

        if (top1 + 1 == top2)
            cout << "Stack Overflow";


        top2--;
        arr[top2] = key;
    }

    int pop1()
    {
        if (top1 < 0)
            cout << "Stack Underflow";


        int top = arr[top1];
        top1--;
        return top;
    }

    int pop2()
    {
        if (top2 >= capacity)
            cout << "Stack Underflow";


        int top = arr[top2];
        top2++;
        return top;
    }
};

int main()
{
    vector<int> arr1 = { 1, 2, 3, 4, 5 };
    vector<int> arr2 = { 6, 7, 8, 9, 10 };

    Stack stack(arr1.size() + arr2.size());

    for (int i: arr1)
        stack.push1(i);


    for (int j: arr2)
        stack.push2(j);


    cout << stack.pop1() << endl;

    cout << stack.pop2() << endl;

    return 0;
}
