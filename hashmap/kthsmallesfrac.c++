#include<bits/stdc++.h>
using namespace std;


    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        priority_queue<pair<float,pair<int,int>>>p;//max

        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                p.push({float(arr[i])/float(arr[j]),{arr[i],arr[j]}});
                if(p.size()>k)p.pop();//when vr size >k pop
            }
        }
        vector<int>ans;
        ans.push_back(p.top().second.first);
                ans.push_back(p.top().second.second);
        return ans;
    }
    int main()
    {
        vector<int>a={1,2,5,6};
        vector<int>ans=kthSmallestPrimeFraction(a,2);
        for(auto i:ans)
        cout<<i<<" ";

    }
