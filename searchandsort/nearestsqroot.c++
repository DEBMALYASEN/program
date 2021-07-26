#include<iostream>
#include<cmath>
using namespace std;
int justGreaterPerfectSq(int n)
{
   int sq_root = sqrt(n);
   return (sq_root + 1)*(sq_root + 1);
   }
int main() {
   int n = 8;
   cout << "Nearest perfect square: " << justGreaterPerfectSq(n);
}
