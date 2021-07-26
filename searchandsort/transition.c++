
#include<bits/stdc++.h>
using namespace std;
int findTransitionPoint(vector<int>a)
{

    int l= 0, u = a.size()-1;

    while (l <= u)
    {

        int mid = (l+u)/2;

        if (a[mid] == 0)
            l = mid+1;


        else if (a[mid] == 1)
        {

            if (mid == 0|| (mid > 0 &&a[mid - 1] == 0))
                return mid;

            u = mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int>a = {0, 0, 0, 0, 1, 1};

    int point = findTransitionPoint(a);

    point >= 0 ? cout<<"Transition point is " << point: cout<<"There is no transition point";
    return 0;
}
