#include<bits/stdc++.h>
using namespace std;
double fx(double x,vector<double>&a)
{
    double ans = 0;

    for(int i=0;i<a.size();i++)
    {
        ans += 1/(x-a[i]);
    }
    return ans;
}
double  bin(double l,double r,vector<double>&a)
{

    double mid;
    double ans=0.0;
    while(l<r)
    {
        mid=(r+l)/2;
        ans=fx(mid,a);


        if(abs(ans) < 0.0000000000001)
        return mid;

        if(ans > 0)
         l = mid;
        else
         r = mid;

    }
}

int main()
{
    vector<double>a={0,10,20,30};

    for(int i=1;i<a.size();i++)
	    {
	        cout<< fixed<<setprecision(1)<<bin(a[i-1], a[i],a)<<" ";
	    }
}
