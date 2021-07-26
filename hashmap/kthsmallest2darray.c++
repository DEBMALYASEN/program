#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxh;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                maxh.push(matrix[i][j]);
                if(maxh.size()>k)
                    maxh.pop();
            }
        }
        return maxh.top();
    }

    int main()
    {
        vector<vector<int>>v={{1,2,3},{4,5,6},{7,8,7}};
        cout<<kthSmallest(v,4);
    }
