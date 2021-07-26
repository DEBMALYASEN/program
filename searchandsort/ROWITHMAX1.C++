
#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<bool>>a)
{

    int max_row_index = 0;

    int  j = a[0].size() - 1;

    for (int i = 0; i < a.size(); i++)
    {

        while (j >= 0 && a[i][j] == 1) {
            j = j - 1;

            max_row_index = i;
        }
    }
      if(max_row_index==0&& a[0][a[0].size()-1]==0)
            return -1;

    return max_row_index;
}

int main()
{
    vector<vector<bool>> a =  { {0, 0, 0, 1},
                                {0, 1, 1, 1},
                                {0, 1, 1, 1},
                                {0, 0, 0, 0}};

    cout << "Index of row with maximum 1s is " << rowWithMax1s(a);

    return 0;
}
