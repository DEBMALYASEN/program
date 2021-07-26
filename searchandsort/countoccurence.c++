
# include <bits/stdc++.h>
using namespace std;

int count(vector<int>a, int x)
{

  auto low = lower_bound(begin(a),end(a), x);

 if (low == end(a) )
     return 0;

  auto high = upper_bound(begin(a), end(a), x);

  return high - low;
}
int main()
{
  vector<int>a = {1, 2, 2, 3, 3, 3, 3};
  int x = 3;

  cout<< count(a, x);

  return 0;
}
