
#include<bits/stdc++.h>
using namespace std;

int minSum(int arr[], int n)
{

    priority_queue <int, vector<int>, greater<int> > p;

    string num1, num2;

    for(int i=0; i<n; i++)
        p.push(arr[i]);

    while(!p.empty())
    {
        num1+=(48 + p.top());
        p.pop();

        if(!p.empty())
        {
            num2+=(48 + p.top());
            p.pop();
        }
    }

    int a = atoi(num1.c_str());
    int b = atoi(num2.c_str());

    return a+b;
}

int main()
{
    int a[] = {6, 8, 4, 5, 2, 3};

    cout<<minSum(a, 6)<<endl;
    return 0;
}
