#include<bits/stdc++.h>
using namespace std;
vector<int> getModifiedArray(int length, vector<vector<int>>updates)
{
        vector<int>a(length,0);

        for(int i = 0; i < updates.size(); i++)
        {
                a[updates[i][0]]    +=updates[i][2];
            if(updates[i][1] < length - 1)
                a[updates[i][1] + 1] -= updates[i][2];
        }
        for(int i = 1; i < length; i++)
            a[i] += a[i - 1];


        return a;
    }
int main()
{
    vector<vector<int>>updates={{1,  3,  2},{2,  4,  3},{0,  2, -2}};
    vector<int>Ans=getModifiedArray(5, updates);
    for(auto i:Ans)
    cout<<i<<" ";
}
