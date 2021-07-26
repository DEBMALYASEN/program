#include<bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n)
{

    stack<int> s;

    int max_area = 0;
    int top;
    int area_with_top;


    int i = 0;


    while (i < n)
    {

        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);


        else
        {
            top = s.top();
            s.pop();


            area_with_top = hist[top] * (s.empty() ? i :  i - s.top() - 1); //right index i left index s.top()

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    while (!s.empty())
    {
        top = s.top();
        s.pop();
        area_with_top = hist[top] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}
int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    cout << "Maximum area is " << getMaxArea(hist, 7);
    return 0;
}
