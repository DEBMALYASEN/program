#include<bits/stdc++.h>
using namespace std;
void printClosest(vector<int>a,vector<int>b,int x)
{

    int diff = INT_MAX;
    int res_l, res_r;


    int l = 0, r = b.size()-1;


    while (l< a.size() && r>=0)
    {

       if (abs(a[l] + b[r] - x) < diff)
       {
           res_l = l;
           res_r = r;
           diff = abs(a[l] + b[r] - x);
       }

       if (a[l] + b[r] > x)
           r--;
       else
           l++;
    }

    cout << "The closest pair is [" << a[res_l] << ", " << b[res_r] << "] \n";
}

int main()
{
    vector<int>a = {1, 4, 5, 7};
    vector<int>b= {10, 20, 30, 40};
    int x = 38;
    printClosest(a,b ,x);
    return 0;
}
