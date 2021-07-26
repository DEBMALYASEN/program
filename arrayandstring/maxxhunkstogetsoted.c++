#include<bits/stdc++.h>
using namespace std;
int maxChunksToSorted(vector<int>& arr)
{
        int max = INT_MIN;
        int chunk=0;
        for(int i=0;i<arr.size();i++)
        {
            if(max<arr[i])
                max = arr[i];
            if(max == i)
                chunk++;
        }
        return chunk;
    }
    int main()
    {
        vector<int>a={0,1,2,3,4};
        cout<<maxChunksToSorted(a);
    }
