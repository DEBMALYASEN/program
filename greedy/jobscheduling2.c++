#include<bits/stdc++.h>
using namespace std;

class Job
{  public:
    char id;
    int deadLine, profit;
};

class DisjointSet
{  public:
    int *parent;

    DisjointSet(int n)
    {
        parent = new int[n+1];
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int s)
    {
        if (s == parent[s])
            return s;
        return parent[s] = find(parent[s]);
    }


    void merge(int u, int v)
    {
        parent[v] = u;
    }
};

bool cmp(Job a, Job b)
{
    return (a.profit > b.profit);
}


int findMaxDeadline(Job a[], int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, a[i].deadLine);
    return ans;
}

int printJobScheduling(Job a[], int n)
{

    sort(a, a + n, cmp);

    int maxDeadline = findMaxDeadline(a, n);

    DisjointSet ds(maxDeadline);


    for (int i = 0; i < n; i++)
    {
        int availableSlot = ds.find(a[i].deadLine);//find max availableSlot

        if (availableSlot > 0)
        {
            ds.merge(ds.find(availableSlot - 1),availableSlot);
            /*for availableSlot will return maximum available slot in set as "availableSlot - 1"*/
            cout << a[i].id << " ";
        }
    }
}


int main()
{
    Job a[] =  { { 'a', 2, 100 }, { 'b', 1, 19 },
                   { 'c', 2, 27 },  { 'd', 1, 25 },
                   { 'e', 3, 15 } };

    printJobScheduling(a, 5);
    return 0;
}
