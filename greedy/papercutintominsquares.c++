#include<bits/stdc++.h>
using namespace std;

int minimumSquare(int a, int b)
{
    long long result = 0, rem = 0;

        swap(a, b);

     //a>=b

    while (b > 0)
    {
        result += a/b;

        long long rem = a % b;
        a = b;
        b = rem;
    }

    return result;
}

//won't wok always
int main()
{
    int n = 13, m = 29;
    cout << minimumSquare(n, m); //13*29
    return 0;
}
