#include <bits/stdc++.h>
using namespace std;
void findSmallest(int m, int s)//m=digits
{
    if (s == 0)
    {
        (m == 1)? cout << "Smallest number is " << 0 : cout << "Not possible";
        return ;
    }

    if (s > 9*m)
    {
        cout << "Not possible";
        return ;
    }

    int res[m];
    s -= 1;

    for (int i=m-1; i>0; i--)
    {

        if (s > 9)
        {
            res[i] = 9;
            s -= 9;
        }
        else
        {
            res[i] = s;
            s = 0;
        }
    }
    res[0] = s + 1;

    cout << "Smallest number is ";
    for (int i=0; i<m; i++)
        cout << res[i];
}

int main()
{
    int s = 9, m = 2;//1 8       s=20 d=3   s=19      9   s=10    99 left1     therefore 299
    findSmallest(m, s);//s=10 d=2     9  s=0    19
    return 0;
}
