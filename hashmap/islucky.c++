include <bits/stdc++.h>
using namespace std;
bool isLucky(int n)
{
    static int counter = 2;

    int next_position = n;
    if(counter > n)
        return 1;
    if(n % counter == 0)
        return 0;
    next_position -= next_position / counter;

    counter++;
    return isLucky(next_position);
}

int main()
{
    int x = 5;
    if( isLucky(x) )
        cout << x << " is a lucky no.";
    else
        cout << x << " is not a lucky no.";
}
