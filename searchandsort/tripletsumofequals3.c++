#include <bits/stdc++.h>
using namespace std;

void findTriplet(vector<int>a)
{
    sort(begin(a),end(a));

    for (int i = a.size() - 1; i >= 0; i--)
    {
        int j = 0;
        int k = i - 1;

        while (j < k)
        {


            if (a[i] == a[j] + a[k])
            {


                cout << "numbers are " << a[i] << " " << a[j] << " " << a[k] << endl;
                return;
            }

            else if (a[i] > a[j] + a[k])
                j += 1;
            else
                k -= 1;
        }
    }


    cout << "No such triplet exists";
}

int main()
{
    vector<int>a = { 5, 32, 1, 7, 10, 50, 19, 21, 2 };


    findTriplet(a);
    return 0;
}
