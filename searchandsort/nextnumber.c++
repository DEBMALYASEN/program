
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void findNextGreater(char number[], int n) {
   int i, j;
   for (i = n-1; i > 0; i--)
      if (number[i] > number[i-1])
         break;
   if (i==0) {
      cout<<"Next number is not possible";
      return;
   }
   int x = number[i-1], smallest = i;
   for (j = i+1; j < n; j++)
      if (number[j] > x && number[j] < number[smallest])
         smallest = j;
  swap(number[i-1],number[smallest]);

   sort(number + i, number + n);
   cout<<number;
   return;
}
int main(){
   char number[] = "341095";
   int n = strlen(number);
   cout<<"The next number with same set of digits is ";
   findNextGreater(number, n);
   return 0;
}
