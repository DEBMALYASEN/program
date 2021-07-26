#include<bits/stdc++.h>
using namespace std;


int kad(vector<int> arr,int n)
{
    int max = 0,min = INT_MIN;

    for(int i = 0;i<n;i++)
    {
        max += arr[i];
        if(max > min)
            min = max;
        if(max < 0)
            max = 0;
    }
    return min;
}

int maxSubarraySumCircular(vector<int>& arr)
{
    int n = arr.size();
    int max = kad(arr,n);

    int sum = 0,cnt = 0;

    for(int i = 0;i<n;i++)
    {
        sum += arr[i];
        arr[i] = -arr[i];
        if(arr[i] > 0)
            cnt++;
    }

    if(cnt == n)
        return max;

    int max_far = kad(arr,n);

    if(max > sum+max_far)
        return max;
    return sum+max_far;
}


int main()
{
    vector<int>a={-5,5,2,1,6,7,7};
    cout<<maxSubarraySumCircular(a);
}
