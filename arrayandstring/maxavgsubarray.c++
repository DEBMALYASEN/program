#include<bits/stdc++.h>
using namespace std;
double findMaxAverage(vector<int>& a, int k)
{
       int n = a.size();
       double sum = 0;
       double max_sum = 0;
       for(int i=0;i<k;i++)
          {
              sum += a[i];
          }
          max_sum = sum;
          for(int i=1;i<n-k+1;i++)
          {
              sum += a[i+k-1] - a[i-1];
              max_sum = max(max_sum,sum);
          }

       return max_sum / k;
   }
   int main()
   {
       vector<int>a={1,12,-5,-6,50,3};
       cout<<findMaxAverage(a,4);
   }
