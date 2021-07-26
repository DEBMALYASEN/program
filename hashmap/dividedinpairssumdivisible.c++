
#include<bits/stdc++.h>
using namespace std;



bool canPair(vector<int>nums, int k)
{
          int n=nums.size();
          unordered_map<int,int>map;
          if(n%2==0)
            {

             for(int i=0;i<n;i++)
               {
             int val=k-((nums[i]%k)+k)%k;

                if(map.find(val)!=map.end())
                        {
                           map[val]--;
                         if(map[val]==0)
                         map.erase(val);
                        }
                 else
                        {
                       if(val==k)
                       map[k]++; // to handle cases when rem = 0;
                       else
                       map[k-val]++;
                        }
                   }
             return (map.size()==0);

                }
    return false;
}
int main()
{
    vector<int>a={9,7,5,3};

    cout<<canPair(a, 6);

}
