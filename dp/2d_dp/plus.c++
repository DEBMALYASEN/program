#include<bits/stdc++.h>
using namespace std;
#define N 10


int minimum(int a, int b, int c, int d)
{
    return min(min(a, b), min(c, d));
}


int calculateSize(int grid[][N])
{
    int left[N][N]={0};
    int right[N][N]={0};
    int top[N][N]={0};
    int bottom[N][N]={0};


    for (int i = 0; i < N; i++)
    {
        top[0][i] = grid[0][i];

        bottom[N - 1][i] = grid[N - 1][i];

        left[i][0] = grid[i][0];

        right[i][N - 1] = grid[i][N - 1];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (grid[i][j] == 1)
             {
                left[i][j] = left[i][j - 1] + 1;
             }

            if (grid[j][i] == 1)
            {
                top[j][i] = top[j - 1][i] + 1;
            }

            if (grid[N - 1 - j][i] == 1)
            {
                bottom[N - 1 - j][i] = bottom[N - j][i] + 1;
            }

            if (grid[i][N - 1 - j] == 1)
            {
                right[i][N - 1 - j] = right[i][N - j] + 1;
            }
        }
    }

    int bar = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int len = minimum(top[i][j], bottom[i][j], left[i][j], right[i][j]);


            if (len  > bar)
                bar = len ;

        }
    }

    return bar-1;
}

int main()
{
    int grid[N][N] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };

    int bar = calculateSize(grid);

    if (bar)
        printf("The largest plus of 1's has a size of %d", 4*bar + 1);


    return 0;
}
