
#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n)
{
    stack<int> s;

    s.push(arr[0]);
    map<int,int>m;

    for (int i = 1; i <2*n; i++)
    {

        if (s.empty())
        {
            s.push(arr[i%n]);
            continue;
        }

        while (!s.empty()  &&  arr[i%n]>= s.top())
        {
            if(m.find(s.top())==m.end())
                m[s.top()]=arr[i%n];

            s.pop();
        }


        s.push(arr[i%n]);
    }

 for(auto i:m)
 {
 if(i.first!=i.second)
     cout<<i.first<<"->"<<i.second<<endl;
     else
     cout<<i.first<<"->"<<-1<<endl;
 }


}

int main()
{
    int arr[] = { 5,6,7,2,11,0,-5,6,99,14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
