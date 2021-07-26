
#include<iostream>
using namespace std;
#define M 8
#define N 8

void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;
    if (screen[x][y] == newC)
        return;


    screen[x][y] = newC;

    floodFillUtil(screen, x+1, y, prevC, newC);
    floodFillUtil(screen, x-1, y, prevC, newC);
    floodFillUtil(screen, x, y+1, prevC, newC);
    floodFillUtil(screen, x, y-1, prevC, newC);
}

void floodFill(int screen[][N], int x, int y, int newC)
{
    int prevC = screen[x][y];
    floodFillUtil(screen, x, y, prevC, newC);
}

int main()
{
    int screen[M][N]={{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
    int x = 0, y = 2, newC = 10;
    floodFill(screen, x, y, newC);





    cout << "Updated screen after call to floodFill: \n";
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
           cout << screen[i][j] << " ";
        cout << endl;
    }
}
