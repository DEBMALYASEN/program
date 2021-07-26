#include <bits/stdc++.h>
using namespace std;

void sortK(vector<int>&a, int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > p(begin(a),begin(a)+k+1);//min heap
   cout<<p.size()<<endl;
    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
       a[index++] = p.top();
        p.pop();
        p.push(a[i]);
    }

    while (p.empty() == false)
     {
        a[index++] = p.top();
        p.pop();
    }
}




int main()
{
    int k,n ;
    cin>>k>>n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin>>a[i];

    sortK(a,n,k);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}
