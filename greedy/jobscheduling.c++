#include<bits/stdc++.h>
using namespace std;
/*
For each job find an empty time slot from deadline to 0. If found empty slot put the job in the slot and mark this slot filled.*/
class Job
{
   char id;
   int dead;
   int profit;
};

bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}


void printJobScheduling(Job a[], int n)
{


    sort(a, a+n, comparison);//high profit to low


    int result[n];
    bool slot[n]={0};


    for (int i=0; i<n; i++)
    {
       for (int j=min(n, a[i].dead)-1; j>=0; j--)
       {
          if (!slot[j])
          {
             result[j] = i;//i job (details)   j is pos and i is job
             slot[j] = 1;//occupied
             break;
          }
       }
    }


    for (int i=0; i<n; i++)
       if (slot[i])
         cout << a[result[i]].id << " ";
}

int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};

    printJobScheduling(arr, 5);
    return 0;
}
