

#include <bits/stdc++.h>
using namespace std;
int maxProfit(int a[], int n,int fee)
{
    int obsp=-a[0],ossp=0,profit=0;
    for(int i=1;i<n;i++)
    {
        int nbsp=0;
        int nssp=0;
        if(ossp-a[i]>obsp)
        nbsp=ossp-a[i];
        else
        nbsp=obsp;

       if(obsp+a[i]-fee>ossp)
       nssp=obsp+a[i]-fee;
       else
       nssp=ossp;

       obsp=nbsp;
       ossp=nssp;
   }

    return ossp;
}

int main()
{
    int price[] = { 10,20,30 };//infinite trans with fee

    cout << "Maximum Profit = "<< maxProfit(price, 3,3);
    return 0;
}
