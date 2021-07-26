#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix)
{
int n = matrix.size();

    for(int i = 0; i < n / 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
int main()
{
    vector<vector<int>>a={{1,2,3},{4,5,6},{7,8,9}};
    rotate(a);
    int n=3;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
