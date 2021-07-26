#include <bits/stdc++.h>
using namespace std;

class Item
{
    int value, weight;
    Item(int value, int weight)
    {
       this->value=value;
       this->weight=weight;
    }
};


bool cmp( Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item a[], int n)
{

    sort(a, a + n, cmp);

    int curWeight = 0;
    double finalvalue = 0.0;


    for (int i = 0; i < n; i++)
    {
        if (curWeight + a[i].weight <= W)
         {
            curWeight += a[i].weight;
            finalvalue += a[i].value;
        }


        else
        {
            int remain = W - curWeight;

            finalvalue += a[i].value* ((double)remain/ (double)a[i].weight);
            break;
        }
    }

    return finalvalue;
}

int main()
{
    int W = 50;
    Item a[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };//v w
    cout << fractionalKnapsack(W, a, 3 );
    return 0;
}
