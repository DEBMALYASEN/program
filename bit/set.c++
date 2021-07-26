#include <iostream>
using namespace std;
class gfg
 {
public:
    unsigned int countSetBits(int n)
    {
        unsigned int count = 0;
        while (n)
        {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    int FlippedCount(int a, int b)
{
    return countSetBits(a^b);
}
int turnOffK(int n, int k)
{

    if (k <= 0) return n;

    return (n & ~(1 << (k - 1)));
}
bool isKthBitSet(unsigned int x, unsigned int k)
{
    return (x & (1 << (k - 1))) ? true : false;
}
bool isPalindrome(unsigned int x)
{
   int l = 1;
   int r = sizeof(unsigned int) * 8;
   while (l < r)
   {
       if (isKthBitSet(x, l) != isKthBitSet(x, r))
           return false;
       l++; r--;
   }
   return true;
}
unsigned int swapBits(unsigned int x)
{

    unsigned int even_bits = x & 0xAAAAAAAA;

    unsigned int odd_bits = x & 0x55555555;

    even_bits >>= 1;
    odd_bits <<= 1;
    return (even_bits | odd_bits);
}
int isPowerOfTwo(unsigned n)
{
    return n && (!(n & (n - 1)));//4 &3==0
}

int PositionRightmostSetbit(int n)
{
    int position = 1;
    int m = 1;

    while (!(n & m))
    {

        m = m << 1;
        position++;
    }
    return position;
}

void bin(unsigned n)
{

    if (n > 1)
        bin(n / 2);

    cout << n % 2;
}
long multiplyBySeven(long n)
{

    return ((n<<3) - n);
}
bool getParity(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n     = n & (n - 1);
    }
    return parity;
}
unsigned int nextPowerOf2(unsigned int n)
{
    unsigned count = 0;

    if (n && !(n & (n - 1)))
        return n;

    while( n != 0)
    {
        n >>= 1;
        count += 1;
    }

    return 1 << count;
}

int isMultipleOf3(int n)
{
    int odd_count = 0;
    int even_count = 0;

    if (n < 0)
        n = -n;
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    while (n)
    {

        if (n & 1)
            odd_count++;

        if (n & 2)
            even_count++;
        n = n >> 2;
    }

    return isMultipleOf3(abs(odd_count - even_count));
}
int fun(unsigned int n)
{
    return n & (n - 1);
}

int leftRotate(int n, unsigned int d)
{

    return (n << d)|(n >> (INT_BITS - d));
}



int rightRotate(int n, unsigned int d)
{
    return (n >> d)|(n << (INT_BITS - d));
}

};
int computeXOR(int n)//xor from 1 to n
{

  if (n % 4 == 0)
    return n;

  if (n % 4 == 1)
    return 1;

  if (n % 4 == 2)
    return n + 1;

  return 0;
}

int main()
{
    gfg g;
    int i = 18;
    g.bin(i);
    return 0;
}
