#include<bits/stdc++.h>
using namespace std;

 int countZeros(vector<vector<int>>a)
    {
        int cnt = 0;
        int row = 0;
        int col = a[0].size()-1;
        while(row<a.size())
        {
            if(a[row][col] == 1)
                col--;
            else
            {
                cnt += col+1;
                row++;
            }
        }
        return cnt;
    }

    int main()
    {
    vector<vector<int>>a = {{0, 0, 0, 0, 1},
                           {0, 0, 0, 1, 1},
                           {0, 0, 1, 1, 1},
                           {0, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1}};

    cout<<countZeros(a);
    }
