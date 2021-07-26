#include <bits/stdc++.h>
using namespace std;

void calcGreatestSmallerElement(string N, int size) {

   int i, j;
   for (i = size - 1; i > 0; i--)
      if (N[i] < N[i - 1])
         break;

   if (i == 0) {
      cout << "Previous number is not possible";
      return;
   }

   int x = N[i - 1], greatest = i;
   for (j = i; j < size; j++)
      if (N[j] < x && N[j] > N[greatest])
         greatest = j;

   swap(N[greatest], N[i - 1]);
   sort(N.begin() + i, N.begin() + size, greater<char>());

   cout<<"The Greatest smaller number with same set of digits is "<<N;

   return;
}

int main() {

   string N = "102";
   int size = N.length();
   cout<<"The number is "<<N<<endl;
   calcGreatestSmallerElement(N, size);

   return 0;
}
