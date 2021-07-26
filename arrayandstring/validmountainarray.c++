#include<bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int>& A)
   {

       if (A.size() < 3)
           return false;
       bool hasStartedRising = false;
       bool hasStartedDescent = false;

       for (int i = 1; i < A.size(); i++)
       {
           if (A[i-1] == A[i])
               return false;

           if (A[i-1] < A[i])
           {
               hasStartedRising = true;
               if (hasStartedDescent)
                   return false;
           }
           else
           {
               hasStartedDescent = true;
               if (!hasStartedRising)
                   return false;
           }
       }

       return hasStartedRising && hasStartedDescent;
   }
   int main()
   {
       vector<int>a={1,2,7,2,1};
       cout<<validMountainArray(a);
   }
