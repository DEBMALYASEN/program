#include<bits/stdc++.h>
using namespace std;
void sortemployees(vector<pair<string,int>>&a)
{
    sort(a.begin(), a.end(), [](const pair<string,int>& p1, const pair<string,int>& p2)
        {
	        if (p1.second == p2.second)
	            return p1.first < p2.first;
	        return p1.second < p2.second;
	    });
}


int main()
{
    vector<pair<string,int>>a={{"xbnnskd", 100}, {"geek", 50}};
    sortemployees(a);

    for(auto i:a)
    cout<<i.first<<" "<<i.second<<" ";
}
