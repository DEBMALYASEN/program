#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target)
  {

       int m = matrix.size();
       int n = matrix[0].size();
       int l = 0, r = m*n - 1;

       while(l<=r)
       {
           int mid = l + (r-l)/2;
           if(matrix[mid/n][mid%n]==target)
           {
               return true;
           }else if(matrix[mid/n][mid%n]>target){
               r = mid - 1;
           }else{
               l = mid + 1;
           }
       }
       return false;
   }
   int main()
   {
       vector<vector<int>> a={{1,2,3},{4,5,6},{7,8,9}};
       cout<<searchMatrix(a,5);
   }
