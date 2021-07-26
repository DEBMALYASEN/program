#include<bits/stdc++.h>
#define M 4
#define N 4
using namespace std;

int arr[M][N] = {
   {10, 8, 10, 10},
   {14, 13, 12, 11},
   {15, 9, 11, 21},
   {16, 17, 19, 20}
};

int findMax(int rows, int mid, int&max)
{
   int maxIndex = 0;
   for (int i = 0; i < rows; i++)
    {
      if (max <arr[i][mid])
      {
         max = arr[i][mid];
         maxIndex = i;
      }
   }
   return maxIndex;
}

int findPeakElement(int rows, int columns, int mid)
 {
   int maxMid = 0;
   int maxMidIndex = findMaxMid(rows, mid, maxMid);

   if (mid == 0 || mid == columns-1)
      return maxMid;

  else  if (maxMid>= arr[maxMidIndex][mid-1] &&maxMid>= arr[maxMidIndex][mid+1])
      return maxMid;

  else if (maxMid<arr[maxMidIndex][mid-1])
      return findPeakElement(rows, columns, mid - mid/2);

  else
   return findPeakElement(rows, columns, mid+mid/2);
}

int main()

{
   int row = 4, col = 4;
   cout<< "The peak element is: "<<findPeakElement(row, col, col/2);
}
