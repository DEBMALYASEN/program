#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& a)
   {
       int i,n=a.size(),maxi=a[0],mini=a[0],maxm=a[0];
       for(i=1;i<n;i++)
       {
           if(a[i]<0) swap(maxi,mini);
           maxi=max(a[i],maxi*a[i]);
           mini=min(a[i],mini*a[i]);
           maxm=max(maxm,maxi);
       }
       return maxm;
   }
   int main()
   {
       vector<int>a={0,1,-1,2,3};
       cout<<maxProduct(a);
   }
