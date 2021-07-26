#include<bits/stdc++.h>
using namespace std;
class Marks
{
public:
    int p;
    int c;
    int m;
    Marks()
    {}
    Marks(int p,int c,int m)
    {
        this->p=p;
        this->c=c;
        this->m=m;
    }
};
bool compare(Marks A,Marks B)
{
    if(A.p!=B.p)
    {
        return A.p<B.p;
    }
    else
    {
        if(A.c!=B.c)
        return A.p>B.p;
        else
        {
            if(A.m!=B.m)
            return A.m<B.m;
        }
    }
}

int main()
{

int n;
cin>>n;
vector<int>p(n);
vector<int>c(n);
vector<int>m(n);
for(int i=0;i<n;i++)
{
    cin>>p[i];
    cin>>c[i];
    cin>>m[i];
}


vector<Marks>M(n);

for(int i=0;i<n;i++)
M[i]=Marks(p[i],c[i],m[i]);


    sort(M.begin(),M.end(),compare);


    for(int i=0;i<n;i++)
    cout<<M[i].p<<" "<<M[i].c<<" "<<M[i].m<<endl;
}
