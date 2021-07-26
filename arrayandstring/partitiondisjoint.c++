#include<bits/stdc++.h>
using namespace std;
int partitionDisjoint(vector<int>A)
   {
       int pivotindex = 0;
       int maxprevpart= A[0];
       int maxToI = A[0];
       for (int i = 1; i < A.size(); i++){
           maxToI = max(maxToI, A[i]);
           if (A[i] < maxprevpart)
           {
               pivotindex= i;
               maxprevpart= maxToI;
           }
       }
       return pivotindex + 1;
   }
   int main()
   {
       vector<int>a={5,0,3,8,6};
       cout<<partitionDisjoint(a);
   }
