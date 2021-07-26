#include<bits/stdc++.h>
using namespace std;

void dfs(int (&a)[100][100],int i ,int j,int (&visited)[100][100],int m ,int n);


void island (int (&a)[100][100],int m ,int n)
{
    int visited[100][100]={0};
    int c=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0 &&!visited[i][j])
            {
                dfs(a,i,j,visited,m,n);
                c++;
            }
        }
    }
    cout<<c;
}
void dfs(int (&a)[100][100],int i ,int j,int (&visited)[100][100],int m ,int n)
{
    if(i<0 || j<0 ||i>=m ||j>=n ||a[i][j]==1||visited[i][j]==1)
    return;
    visited[i][j]=1
    dfs(a,i-1,j,visited,m,n);
    dfs(a,i,j+1,visited,m,n);
    dfs(a,i,j-1,visited,m,n);
    dfs(a,i+1,j,visited,m,n);

}



int main()
{
    int m ,n;
    cin>>m>>n;
    int a[100][100];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
    island(a,m,n);
}
