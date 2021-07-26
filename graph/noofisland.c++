#include<bits/stdc++.h>
using namespace std;
#define M 4
#define N 4
void floodFillUtil(int  mat[][N], int x, int y)
{

    if (x < 0 || x >= M || y < 0 || y >= N||mat[x][y]==0)
        return;

    mat[x][y] = 0;


    floodFillUtil(mat, x+1, y);
    floodFillUtil(mat, x-1, y);
    floodFillUtil(mat, x, y+1);
    floodFillUtil(mat, x, y-1);
}

int noofisland(int mat[][N])
{


   int a=0;
      for (int i=0; i<M; i++)
      {
      for (int j=0; j<N; j++)
      {
         if (mat[i][j] == 1)
         {
           floodFillUtil(mat, i, j);
          a++;
       }
     }
 }



  return a;

}

int main()
{
    int mat[][N] =  {{0,0,0,0},
                      {1,0,1,0},
                      {0,1,1,0},
                      {0,0,1,0},
                    };
    cout<<noofisland(mat);



    return 0;
}
