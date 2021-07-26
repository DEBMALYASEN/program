#include<bits/stdc++.h>
using namespace std;
vector<int> getRow(int n)
{
        vector<vector<int>> vec(n+1);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                vec[i].push_back(1);
                else
                vec[i].push_back(vec[i-1][j]+vec[i-1][j-1]);
            }
        }
        return vec[n];
    }
    int main()
    {
        int n;
        cin>>n;
        vector<int>a=getRow(n);
        for(auto i :a)
        cout<<i<<" ";
    }
