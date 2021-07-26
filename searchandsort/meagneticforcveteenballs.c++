#include<bits/stdc++.h>
using namespace std;

     int maxDistance(vector<int>position, int m)
     {
        sort(position.begin(),position.end());
        int size = position.size();

        int l = 0;
        int r = position[size-1] - position[0];
        while(l<r)
        {
            int mid = l + (r-l+1)/2;
            int balls = 1;

            int posCurr = position[0];
            for(int i=1;i<size;i++)
            {
                if(position[i]-posCurr>=mid)
                {
                    posCurr = position[i];
                    balls++;
                }
            }
            if(balls>=m)
                l=mid;
            else
                r=mid-1;

        }
        return l;
    }
    int main()
    {
         vector<int> position = {1,2,3,4,7};
         int  m = 3;
         cout<<maxDistance(position,m);
    }
