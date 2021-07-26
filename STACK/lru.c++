#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    list<int> q;

    unordered_map<int, list<int>::iterator>  m;

    int csize;

public:
    LRUCache(int);
    void refer(int);
    void display();
};

LRUCache::LRUCache(int n)
{
    csize = n;
}


void LRUCache::refer(int x)
{

    if (m.find(x) == m.end())
    {
        if (q.size() == csize)
        {

            int last = q.back();
            q.pop_back();
            m.erase(last);
        }
    }


    else
        q.erase(m[x]);


    q.push_front(x);
    m[x] = q.begin();
}


void LRUCache::display()
{

    for(auto i:q)
        cout << i ;

    cout << endl;
}

int main()
{
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}
