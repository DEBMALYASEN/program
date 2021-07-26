#include<bits/stdc++.h>
using namespace std;
int minEatingSpeed(vector<int>& piles, int hours)
 {
        int result = INT_MAX;
        int maxi = 0;

        for(int i = 0;i<piles.size();i++)
            maxi = max(maxi,piles[i]);

        int low = 1;
        int high = maxi;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int tot = 0;
            for(int i = 0;i<piles.size();i++)
                tot += ceil((piles[i]*1.0)/mid);

            if(tot <= hours)
            {
                high = mid-1;
                result = min(result,mid);
            }
            else
                low = mid+1;
        }
        return result;
    }
    int main()
    {
        vector<int>piles={30,11,23,4,20};
        int hours=5;
        cout<<minEatingSpeed(piles,hours);
    }
