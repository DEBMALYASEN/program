#include<bits/stdc++.h>
#define N 4
using namespace std;

void findMax (int arr[][N])
{
    int row = 0, i, j;
    for (i=0, j=N-1; i<N;i++)
    {

        while (arr[i][j] == 1 && j >= 0)
        {
            row = i;
            j--;
        }
    }
    cout << "Row number = " << row+1;
    cout << ", MaxCount = " << N-1-j;
}

// driver program
int main()
{
    int arr[N][N] = {0, 0, 0, 1,
                     0, 0, 0, 1,
                     0, 0, 0, 0,
                     0, 1, 1, 1};
    findMax(arr);
    return 0;
}
