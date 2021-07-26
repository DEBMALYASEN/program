#include<bits/stdc++.h>
using namespace std;
    int maxArea(vector<int>& A)
    {
        int i = 0;
        int j = A.size()-1;

        int maxArea = 0;
        while(i<j){
            maxArea = max(maxArea , (j-i)*min(A[i],A[j]));
            if(A[i]<A[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
int main()
{
    vector<int>A={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(A);
}
