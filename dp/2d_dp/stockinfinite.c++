

#include <bits/stdc++.h>
using namespace std;
int maxProfit(int a[], int n)
{
    int bd=0,sd=0,profit=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>=a[i-1])
        sd++;
        else
        {
            profit+=a[sd]-a[bd];
            bd=sd=i;
        }

    }
    profit+=a[sd]-a[bd];

    return profit;
}

int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };//infinite trans

    cout << "Maximum Profit = "<< maxProfit(price, 7);
    return 0;
}
