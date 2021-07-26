#include<bits/stdc++.h>
using namespace std;
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
{
        vector<pair<int, int>> jobs;
        int N = profit.size(), res = 0, i = 0, best = 0;
        for (int j = 0; j < N; ++j)
            jobs.push_back(make_pair(difficulty[j], profit[j]));
        sort(jobs.begin(), jobs.end());

        sort(worker.begin(), worker.end());

        for (int & ability : worker)
        {
            while (i < N && ability >= jobs[i].first)
                best = max(jobs[i++].second, best);


            res += best;
        }
        return res;

    }
    int main()
    {

    vector<int>difficulty = {2,4,6,8,10};
    vector<int> profit = {10,20,30,40,50};
    vector<int>worker = {4,5,6,7};

    cout<<maxProfitAssignment(difficulty,profit,worker);
    }
