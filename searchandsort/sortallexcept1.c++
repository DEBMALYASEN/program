
#include <bits/stdc++.h>
using namespace std;

int sortExceptK(vector<int>&a,int k)
{

    swap(a[k], a[a.size()-1]);

    sort(begin(a), begin(a)+ a.size() - 1);


    int last = a[a.size()-1];


    for (int i=a.size()-1; i>k; i--)
       a[i] = a[i-1];


    a[k] = last;
}

int main()
{
    vector<int>a={10, 4, 11, 7, 6, 20 };
    int k = 2;

    sortExceptK(a, k);


    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
}
