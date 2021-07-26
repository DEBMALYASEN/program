#include <bits/stdc++.h>
using namespace std;

int minimumDays(int N, int D1[], int D2[])
{
    int ans = INT_MIN;
    vector<pair<int, int> > vect;

    for (int i = 0; i < N; i++)
        vect.push_back(make_pair(D1[i], D2[i]));

    sort(vect.begin(), vect.end());// (4,3)(5,2),(6,1)

    for (int i = 0; i < N; i++)
    {
        if (vect[i].second >= ans)
            ans = vect[i].second;
        else
            ans = vect[i].first;
    }
                                    //    ans=1 ,2,3
    return ans;
}


int main()
{
    int N = 3;
    int D1[] = { 6, 5, 4 };
    int D2[] = { 1, 2, 3 };

    cout<<minimumDays(N, D1, D2);

    return 0;
}
