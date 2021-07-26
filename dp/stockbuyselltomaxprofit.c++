
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int prices[], int n)//max difference  between elements of the array
{
    int cost = 0;
    int maxCost = 0;

    if (n == 0)
        return 0;
    
    int min_price = prices[0];

    for(int i = 0; i < n; i++)
    {


        min_price = min(min_price, prices[i]);  // to get max diff delete the min from all and find max

        cost = prices[i] - min_price;

        maxCost = max(maxCost, cost);
    }
    return maxCost;
}

int main()
{

    int prices[] = { 7, 1, 5, 3, 6, 4 };


    cout << maxProfit(prices, 6);

    return 0;
}
