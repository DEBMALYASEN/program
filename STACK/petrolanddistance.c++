
#include <bits/stdc++.h>
using namespace std;

class petrolPump
{
    public:
    int petrol;
    int distance;
};



int printTour(petrolPump a[], int n)
{
    int start = 0;
    int end = 1;

    int curr_petrol = a[start].petrol - a[start].distance;

    while (end != start || curr_petrol < 0)
    {
        while (curr_petrol < 0 && start != end)
        {
            curr_petrol = curr_petrol-(a[start].petrol - a[start].distance);
            start = (start + 1) % n;
            if (start == 0)
            return -1;
        }
        curr_petrol += a[end].petrol - a[end].distance;

        end = (end + 1) % n;
    }

    return start;
}


int main()
{
    petrolPump a[] = {{6, 4}, {3, 6}, {7, 3}};

    int start = printTour(a, 3);

    (start == -1)? cout<<"No solution": cout<<"Start = "<<start;

    return 0;
}
