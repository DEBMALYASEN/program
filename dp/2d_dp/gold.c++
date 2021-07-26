#include<bits/stdc++.h>
using namespace std;
void goldmine(int a[1000][1000],int n,int m)
{
    int goldtable[1000][1000]={0};
    /*for(int i=0;i<n;i++)
        goldtable[i][m-1]=a[i][m-1];*/

    cout<<"out";

/*    for(int i=0;i<n;i++)
    {
        for(int j=m-2;j>=0;j--)
        {

            int x=a[i+1][j-1];
            int y=a[i+1][j];
            int z =a[i+1][j+1];

         goldtable[i][j]=a[i][j]+max(max(x,y),z);
        }
    }
*/


}

int main()
{

 int m,n;
 cin>>m>>n;
 int a[1000][1000];
 for(int i=0;i<m;i++)
 {
     for(int j=0;j<n;j++)
     cin>>a[i][j];
 }
 cout<<"no";
 goldmine(a,m,n);

}
