#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int aux[], int l, int mid, int h)
{
    int k = l;

    for (int i = l; i <= mid; i++)
    {
        if (a[i] < 0)
            aux[k++] = a[i];

    }

    for (int j = mid + 1; j <= h; j++)
    {
        if (a[j] < 0)
            aux[k++] = a[j];

    }

    for (int i = l; i <= mid; i++)
    {
        if (a[i] >= 0)
            aux[k++] = a[i];

    }

    for (int j = mid + 1; j <= h; j++)
    {
        if (a[j] >= 0)
            aux[k++] = a[j];

    }

    for (int i = l; i <= h; i++)
        a[i] = aux[i];

}


void partition(int a[], int aux[], int l, int h)
{
    if (h == l)
        return;
    int mid=(h+l)/2;

    partition(a, aux, l, mid);
    partition(a, aux, mid + 1, h);

    merge(a, aux, l, mid, h);
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int aux[100];
    for(int i=0;i<n;i++)
    aux[i]=a[i];
    partition(a,aux,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

}
