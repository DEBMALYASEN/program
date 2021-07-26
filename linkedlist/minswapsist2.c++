#include<bits/stdc++.h>
using namespace std;
int minimum(int a[],int n)
{
    bool visited[n+1]={0};
    int i,j;
    int min=0;
    for ( i = 0; i < 2 * n; i++)
     {

        if (!visited[a[i]])
         {
            visited[a[i]] = true;
            int  c=0;

            for ( j = i + 1; j < 2 * n; j++)
             {


                if (!visited[a[j]])
                    c++;

                else if (a[i] == a[j])
                    min += c;
            }
        }
      }
      return min;
}



int main()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];

    n/=2;


      cout<<minimum(a,n)<<endl;
  }
