#include<bits/stdc++.h>
using namespace std;

void calculateSpan(int price[], int n, int Stock[])
{

    stack<int> s;
    s.push(0);

    Stock[0] = 1;


    for (int i = 1; i < n; i++)
    {

        while (!s.empty() && price[s.top()] <= price[i])
            s.pop();


        Stock[i] = (s.empty()) ? (i + 1) : (i - s.top());

        s.push(i);
    }
}



int main()
{
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int S[100];

    calculateSpan(price, 6, S);

    for (int i = 0; i < 6; i++)
        cout << S[i] << " ";


    return 0;
}
