
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int m, int n)
{
    return (x >= 0 && x < m &&
            y >= 0 && y < n);
}

double findProbability(int m, int n, int x,int y, int N)
{

    if (!isSafe(x, y, m, n))
        return 0.0;

    if (N == 0)
        return 1.0;

    double prob = 0.0;

    // move up
    prob += findProbability(m, n, x - 1,
                            y, N - 1) * 0.25;

    // move right
    prob += findProbability(m, n, x,
                            y + 1, N - 1) * 0.25;

    // move down
    prob += findProbability(m, n, x + 1,
                            y, N - 1) * 0.25;

    // move left
    prob += findProbability(m, n, x,
                            y - 1, N - 1) * 0.25;

    return prob;
}

int main()
{

    int m = 5, n = 5;

    int i = 1, j = 1;
    int N = 2;

    cout << "Probability is "<< findProbability(m, n, i, j, N);

    return 0;
}
