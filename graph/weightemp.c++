#include<bits/stdc++.h>
using namespace std;
template<class T>
class graph
{
    map<T,list<pair<T,int> >> l;
public:
    void addEdge(T x,T y ,int w,int directed=true)
    {
        l[x].push_back(make_pair(y,w));
        if(!directed)
        l[y].push_back(make_pair(x,w));
    }
    void printadj()
    {
        for(auto i:l)
        {
            cout<<i.first<<"->"<<" ";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<")"<<"";
            }
            cout<<endl;
        }
    }
    int prim_mst()
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int visited[100]={0};
        int ans=0;
        q.push({0,0});
        while(!q.empty())
        {
            auto best=q.top();
            q.pop();
            int to=best.second;
            int weight=best.first;
            if(visited[to])
            continue;
            ans+=weight;
            visited[to]=1;
            for(auto x:l[to])
            {
                if(!visited[x.first])
                {
                    q.push({x.second,x.first});
                }
            }
        }
        return ans;
    }
};
int main()
{
    graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    cout<<g.prim_mst();
}
