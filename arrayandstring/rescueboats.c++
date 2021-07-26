#include<bits/stdc++.h>
using namespace std;
int numRescueBoats(vector<int>& people, int limit)
{

       sort(people.begin(),people.end()) ;

        int n=people.size(),i=0,j=n-1,count=0;

        while(i<=j)
        {
           if(people[i]+people[j]<=limit)//if only less tham limit then increase eight
           i++;

           count++;//count
           j--;//decrease eight
        }

return count;
    }
    int main()
    {
        vector<int>a={3,2,2,1};
        int limit=3;
        cout<<numRescueBoats(a,limit);
    }
