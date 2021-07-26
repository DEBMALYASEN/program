#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 3


void printPaths(int mat[][N], vector<int> &route, int i, int j)
{

    if (i == M - 1 && j == N - 1)
    {

        for (int i: route)
        {
            cout << i << " — ";
        }

        cout << mat[i][j] << endl;
        return;
    }

    route.push_back(mat[i][j]);


    if (i + 1 < M)
    {
        printPaths(mat, route, i + 1, j);
    }


    if (j + 1 < N)
    {
        printPaths(mat, route, i, j + 1);
    }


    if (i + 1 < M && j + 1 < N)
    {
        printPaths(mat, route, i + 1, j + 1);
    }
 
    route.pop_back();
}

void printPaths(int mat[][N])
{
    vector<int> route;

    printPaths(mat, route, 0, 0);
}

int main()
{
    int mat[][N] =
    {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    printPaths(mat);

    return 0;
}
