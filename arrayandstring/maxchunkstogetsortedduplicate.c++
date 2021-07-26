#include<bits/stdc++.h>
using namespace std;



int maxChunksToSorted(vector<int>& arr)

{
       vector<int> minimums(arr.size());

       minimums[arr.size()-1] = arr[arr.size()-1];
       for(int i = arr.size() - 2 ; i >= 0 ; i--)
               minimums[i] = min(minimums[i+1], arr[i]);

       int chunksCount = 0;
       int maximum = arr[0];

       if(arr.size() > 1 and maximum <= minimums[1])
           chunksCount++;

       for(int i = 1; i < arr.size()-1 ; i++)
       {
           maximum = max(maximum, arr[i]);
           if(maximum <= minimums[i+1])
               chunksCount++;
       }

       return chunksCount+1;
   }
   int main()
   {
       vector<int>a={0,1,2,3,4};
       cout<<maxChunksToSorted(a);
   }
