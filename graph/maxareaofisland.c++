#include<bits/stdc++.h>
using namespace std;
#define M 4
#define N 4
void floodFillUtil(int  mat[][N], int x, int y, int &area)
{

    if (x < 0 || x >= M || y < 0 || y >= N||mat[x][y]==0)
        return;

    mat[x][y] = 0;
    area++;

    floodFillUtil(mat, x+1, y, area);
    floodFillUtil(mat, x-1, y, area);
    floodFillUtil(mat, x, y+1, area);
    floodFillUtil(mat, x, y-1, area);
}

int maxareaofisland(int mat[][N])
{


   int area=0,maxarea=INT_MIN;
      for (int i=0; i<M; i++)
      {
      for (int j=0; j<N; j++)
      {
         if (mat[i][j] == 1)
         {
           floodFillUtil(mat, i, j, area);
           maxarea=max(maxarea,area);
           area=0;
       }
     }
 }



  return maxarea;

}

int main()
{
    int mat[][N] =  {{0,0,0,0},
                      {1,0,1,0},
                      {0,1,1,0},
                      {0,0,1,0},
                    };
    cout<<maxareaofisland(mat);



    return 0;
}
