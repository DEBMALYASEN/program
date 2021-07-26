#include<bits/stdc++.h>
using namespace std;

void maxOverlap(vector<int>& start, vector<int>& end )
{

    int n= start.size();

    int maxa=*max_element(start.begin(), start.end());

    int maxb=*max_element(end.begin(), end.end());

    int maxc = max(maxa, maxb);

    int x[maxc + 2]={0};


        int cur = 0, idx;


        for(int i = 0; i < n; i++)
        {
            ++x[start[i]];
            --x[end[i]+1];
        }

        int maxy = INT_MIN;

        for(int i = 0; i <= maxc; i++)
        {
            cur += x[i];
            if(cur>=maxy)
            {
                maxy = cur;
                idx = i;

            }
        }

        cout<<"Maximum value is "<<maxy<<" at position "<<idx<<endl;
}

int main()
{
        vector<int> start = {1, 2, 3},end = {4, 6, 5};

        maxOverlap(start,end);
    return 0;
}
