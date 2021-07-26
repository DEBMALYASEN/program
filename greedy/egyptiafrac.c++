#include <iostream>
using namespace std;

void printEgyptian(int n, int d)
{
    if (d == 0 || n == 0)
        return;

    if (d%n == 0)
    {
        cout << "1/" << d/n;
        return;
    }

    if (n%d == 0)
    {
        cout << n/d;
        return;
    }

    if (n> d)
    {
        cout << n/d << " + ";
        printEgyptian(n%d, d);
        return;
    }


    int num = d/n + 1;
    cout << "1/" << num << " + ";


    printEgyptian(n*num-d, d*num);
 }


int main()
{
    int n = 1, d = 6;
    cout << "Egyptian Fraction Representation of "
         << n<< "/" << d << " is\n ";
    printEgyptian(n, d);
    return 0;
}
