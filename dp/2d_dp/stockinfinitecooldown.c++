#include <bits/stdc++.h>
using namespace std;
int maxProfit(int a[], int n)
{
    int obsp=-a[0],ossp=0,ocsp=0;
    for(int i=1;i<n;i++)
    {
        int nbsp=0;
        int nssp=0;
        int ncsp=0;
        if(ocsp-a[i]>obsp)
        nbsp=ocsp-a[i];
        else
        nbsp=obsp;

       if(obsp+a[i]>ossp)
       nssp=obsp+a[i];
       else
       nssp=ossp;
       if(ossp>ocsp)
       ncsp=ossp;
       else
       ncsp=ocsp;

       obsp=nbsp;
       ossp=nssp;
       ocsp=ncsp;
   }

    return ossp;
}

int main()
{
    int price[] = { 10,20,30 };//infinite trans with cooldaown

    cout << "Maximum Profit = "<< maxProfit(price, 3);
    return 0;
}
