
#include <iostream>
using namespace std;


#define M 5
#define N 5
int findSubmatrixSum(int mat[M][N], int p, int q, int r, int s)
{
    int sum[M][N];

    sum[0][0] = mat[0][0];


    for (int j = 1; j < N; j++) {
        sum[0][j] = mat[0][j] + sum[0][j - 1];
    }
 ]
    for (int i = 1; i < M; i++) {
        sum[i][0] = mat[i][0] + sum[i - 1][0];
    }

\
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1]
                - sum[i - 1][j - 1];
        }
    }
 
    int total = sum[r][s];

    if (q - 1 >= 0) {
        total -= sum[r][q - 1];
    }

    if (p - 1 >= 0) {
        total -= sum[p - 1][s];
    }

    if (p - 1 >= 0 && q - 1 >= 0) {
        total += sum[p - 1][q - 1];
    }

    return total;
}

int main()
{
    int mat[M][N] =
    {
        { 0, 2, 5, 4, 1 },
        { 4, 8, 2, 3, 7 },
        { 6, 3, 4, 6, 2 },
        { 7, 3, 1, 8, 3 },
        { 1, 5, 7, 9, 4 }
    };

    int p = 1, q = 1, r = 3, s = 3;

    cout << findSubmatrixSum(mat, p, q, r, s);

    return 0;
}
