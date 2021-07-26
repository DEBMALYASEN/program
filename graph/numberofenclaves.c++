#include<bits/stdc++.h>
using namespace std;
#define M 4
#define N 4


// A recursive function to replace previous value 'prevV' at  '(x, y)'
// and all surrounding values of (x, y) with new value 'newV'.
void floodFillUtil(char mat[][N], int x, int y, char prevV, char newV)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (mat[x][y] != prevV)
        return;

    // Replace the color at (x, y)
    mat[x][y] = newV;

    // Recur for north, east, south and west
    floodFillUtil(mat, x+1, y, prevV, newV);
    floodFillUtil(mat, x-1, y, prevV, newV);
    floodFillUtil(mat, x, y+1, prevV, newV);
    floodFillUtil(mat, x, y-1, prevV, newV);
}

int rnumberofenclaves(char mat[][N])
{


   for (int i=0; i<M; i++)   // Left side
      if (mat[i][0] == 1)
        floodFillUtil(mat, i, 0, 1, 0);

   for (int i=0; i<M; i++)  //  Right side
      if (mat[i][N-1] == 1)

        floodFillUtil(mat, i, N-1, 1, 0);
   for (int i=0; i<N; i++)   // Top side
      if (mat[0][i] == 1)
        floodFillUtil(mat, 0, i, 1, 0);

   for (int i=0; i<N; i++)  // Bottom side
      if (mat[M-1][i] == 1)
        floodFillUtil(mat, M-1, i, 1, 0);

   // Step 3: Replace all '-' with 'X'
   int c=0;
   for (int i=0; i<M; i++)
      for (int j=0; j<N; j++)
         if (mat[i][j] == 1)
            c++;


  return c;

}

int main()
{
    char mat[][N] =  {{0,0,0,0},
                      {1,0,1,0},
                      {0,1,1,0},
                      {0,0,0,0},
                    };
    cout<<rnumberofenclaves(mat);



    return 0;
}
