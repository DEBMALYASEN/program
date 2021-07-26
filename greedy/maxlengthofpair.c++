#include<bits/stdc++.h>
using namespace std;

class val
{
public:
int first;
int second;
};

  bool cmp( val a,val b)
   {
   return(a.second<b.second);//sort based o b vlaues
   }

  int findLongestChain(val a[],int n)
   {

    sort(a,a+n,cmp);

     int j=0,sum=1;

      for(int i=0;i<n-1;i++)
         {
           if(a[i+1].first>a[j].second)
            {
              sum++;
              j=i+1;
             }
          }
      return sum;
     }
int main()//{5,24},{15,28},{27,40},{39,60},{50.9}}
{
    val a[]={{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    cout<<findLongestChain(a,5);
}
