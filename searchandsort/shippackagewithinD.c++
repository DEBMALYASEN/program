#include<bits/stdc++.h>
using namespace std;
// Will check if "limit" weight is sufficient for the ship to transfer complete weight
 bool isValid(vector<int>weights, int limit, int days)
 {
     int sum=0;
     int noOfDays = 1;
     for(int i=0;i<weights.size();i++)
     {
         sum+=weights[i];
         if(sum>limit)
         {
             sum=weights[i];
             ++noOfDays;
         }
         if(noOfDays>days)
             return false;
     }
     return true;
 }


     int shipWithinDays(vector<int>weights, int days)
      {
        int sum=0;
        int min= INT_MIN;

        for(int i: weights)
        {
            sum+=i;
            min = max(min, i);
        }

        int start = min;
        int end = sum;
        int res=0;
        int mid=0;

        while(start<=end)
        {
            mid = start + (end-start)/2;

            if(isValid(weights, mid, days))
            {
                end = mid-1;
                res= mid;
            }
            else
                start = mid+1;

        }

        return res;
    }

int main()//split array largest sum
          // painter partition prob
          //book allocation prob
{
    vector<int>weights={12,34,67,90};
    int days=2;
    int capacity=shipWithinDays(weights,days);
    cout<<capacity;
}
