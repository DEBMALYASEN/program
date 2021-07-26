#include<bits/stdc++.h>
using namespace std;
int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
   {
       sort(horizontalCuts.begin(), horizontalCuts.end());

       sort(verticalCuts.begin(),verticalCuts.end());

       long height=horizontalCuts[0];

       long width=verticalCuts[0];

       for(int i=1; i<horizontalCuts.size(); i++)
           height=max(height, (long) horizontalCuts[i]-horizontalCuts[i-1]);

       for(int i=1; i<verticalCuts.size(); i++)
           width=max(width, (long)verticalCuts[i]-verticalCuts[i-1]);


       height=max(height,(long)h-horizontalCuts[horizontalCuts.size()-1]);
       width=max(width, (long)w-verticalCuts[verticalCuts.size()-1]);
       return (height*width);
   }
   int main()
   {
       int h=5;
       int w=5;
       vector<int>horizontalCuts = {1,2,4};
       vector<int>verticalCuts = {1,3};
       cout<<maxArea(h,w,horizontalCuts,verticalCuts);
   }
