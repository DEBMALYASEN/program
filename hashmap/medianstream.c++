#include<bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    double median;

    MedianFinder()
    {

        median = 0;
    }

    void addNum(int num)
     {


        if(max_heap.size() > min_heap.size())

        {
            if(num < median)
            {

                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }

            else

                min_heap.push(num);


            median = (double)(min_heap.top() + max_heap.top()) / 2.0;
        }

        else if (max_heap.size() < min_heap.size())
        {


            if(num > median)
            {

                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }

            else
                max_heap.push(num);


            median = (double)(min_heap.top() + max_heap.top()) / 2.0;
        }


        else
        {
            if( num < median)
            {
                max_heap.push(num);
                median = (double)max_heap.top();
            }

            else
            {
                min_heap.push(num);
                median = (double)min_heap.top();
            }
        }

    }

    double findMedian()
    {
        return median;
    }
};
int main()
{
 MedianFinder* a = new MedianFinder();
 a->addNum(5);
 double param_2 ;
 param_2 = a->findMedian();
cout<<param_2;
a->addNum(6);
 param_2 = a->findMedian();
cout<<param_2; a->addNum(0);
  param_2 = a->findMedian();
cout<<param_2; a->addNum(8);
  param_2 = a->findMedian();
cout<<param_2; a->addNum(66);
  param_2 = a->findMedian();
cout<<param_2; a->addNum(0);
  param_2 = a->findMedian();
cout<<param_2; a->addNum(51);
 param_2 = a->findMedian();
cout<<param_2; a->addNum(15);
  param_2 = a->findMedian();
cout<<param_2; a->addNum(75);
  param_2 = a->findMedian();
cout<<param_2; a->addNum(5);
  param_2 = a->findMedian();
cout<<param_2;
}
