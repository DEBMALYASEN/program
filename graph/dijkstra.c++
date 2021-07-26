#include<bits/stdc++.h>
using namespace std;
template<class T>
class graph
{
    map<T,list<pair<T,int> >> l;
public:
    void addEdge(T x,T y ,int w,int directed=false)
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



    void dijkstra(T src)
    {
        unordered_map<T,int>dis;
        for(auto i:l)
        dis[i.first]=INT_MAX;

        set<pair<int,T>>s;

        dis[src]=0;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            auto p=*(s.begin());

            T node =p.second;
            int nodedist=p.first;
            //dis node
            s.erase(s.begin());

            for(auto childPair:l[node])
            {
                if(nodedist+childPair.second<dis[childPair.first])
                {
                    T dest=childPair.first;
                    auto f=s.find(make_pair(dis[dest],dest));
                    if(f!=s.end())
                    s.erase(f);

                    dis[dest]=nodedist+childPair.second;
                    s.insert(make_pair(dis[dest],dest));
                }
            }
        }

        for(auto d:dis)
            cout<<d.first<<"   located at a dis   "<<d.second<<"  from source  "<<src<<" "<<endl;

    }

};


    int main()
    {
        graph<string> g;
        g.addEdge("Amritsar","Delhi",1);
        g.addEdge("Amritsar","Jaipur",4);
        g.addEdge("Jaipur","Delhi",2);
        g.addEdge("Jaipur","Mumbai",8);
        g.addEdge("Bhopal","Agra",2);
        g.addEdge("Mumbai","Bhopal",3);
        g.addEdge("Agra","Delhi",1);
        g.dijkstra("Agra");
    }
