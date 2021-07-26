#include<bits/stdc++.h>
using namespace std;

int findMissingUtil(vector<int>&a, int diff)
{
    int low=0;
    int high=a.size()-1;

while(low<high)
{
    int mid = low + (high - low) / 2;

    if (a[mid + 1] - a[mid] != diff)
        return (a[mid] + diff);


    else if (mid > 0 && a[mid] - a[mid - 1] != diff)s
        return (a[mid - 1] + diff);

    else if (a[mid] == a[0] + mid * diff)
            low=mid+1;

     else
             high=mid-1;
}

}
int findMissing(vector<int>&a)
{

    int diff = (a[a.size() - 1] - a[0]) / a.size();

    return findMissingUtil(a,diff);
}


int main()
{

    vector<int>a = {2, 4, 8, 10, 12, 14};

    cout << "The missing element is " << findMissing(a);
    return 0;
}
