#include<bits/stdc++.h>
using namespace std;
int lengthremovedup(vector<int> A)
{
int count = 0;
for(int i = 1; i < A.size(); i++)
{
    if(A[i] == A[i-1])
    count++;
    else
    A[i-count] = A[i];
}
return A.size()-count;
}
int main()
{
    vector<int>A={5,5,6,7,10,10,15};
    cout<<lengthremovedup(A);
}
