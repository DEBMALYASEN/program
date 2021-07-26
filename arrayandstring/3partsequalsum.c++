#include<bits/stdc++.h>
using namespace std;
bool canThreePartsEqualSum(vector<int>& A,int n)
 {
 auto total = accumulate(begin(A), end(A), 0);
 if (total % 3 != 0)
     return false;

int sum=0,parts=0;

 for (int i = 0; i < n; ++i)
 {
   sum += A[i];
   if (sum == ( total / 3))
    {
       ++parts;
       sum=0;
    }

 }
 return parts>=3;
 }
 int main()
 {
     vector<int>a={1,2,3,5,1,0,1,4,1};
     cout<<canThreePartsEqualSum(a,9);
 }
