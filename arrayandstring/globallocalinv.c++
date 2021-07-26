#include<bits/stdc++.h>
using namespace std;
bool isIdealPermutation(vector<int>& nums)

{
for(auto i = 0; i < nums.size(); i++)
    if(abs(nums[i] - i) > 1)
        return false;
return true;
}
int main()//glovbal and local inv
{
    vector<int>a={2,1,0};
    cout<<isIdealPermutation(a);
}
