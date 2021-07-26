#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
   int i, j, k;
   int count = 0;
   i = left;
   j = mid;
   k = left;
   while (i < mid && j <= right)

   {
      if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
      else
      {
         temp[k++] = arr[j++];
         count += (mid - i);
      }
   }
   while (i <mid)
      temp[k++] = arr[i++];

   while (j <= right)
      temp[k++] = arr[j++];

   for (i=left; i <= right; i++)
      arr[i] = temp[i];

   return count;
}
int mergeSort(int arr[], int temp[], int left, int right)
{
   int mid, count = 0;
   if (right > left)
   {
      mid = (right + left)/2;

      count = mergeSort(arr, temp, left, mid);
      count += mergeSort(arr, temp, mid+1, right);
      count += merge(arr, temp, left, mid+1, right);
   }
   return count;
}

int arrInversion(int arr[], int n)
{
   int temp[n];
   return mergeSort(arr, temp, 0, n - 1);
}

int main()
{
   int arr[] = {1, 5, 6, 4, 20};
   int n = 5;
   cout << arrInversion(arr, n);
}
