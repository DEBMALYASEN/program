#include<bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char>& letters, char target)
   {
   int start = 0;
   int end = letters.size()-1;
   while(start<=end)
   {
       int mid = start + (end-start)/2 ;
       if(letters[mid]<=target)
           start = mid+1;
       else
           end = mid-1;
   }
   return (letters[start%letters.size()]);

   }
   int main()
   {
       vector<char>s={'a','f','y'};
       cout<<nextGreatestLetter(s,'z');
   }
