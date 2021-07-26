#include<bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *a;
    int capacity;
    int heap_size;
public:

    MinHeap(int capacity)
    {
        heap_size=0;
        this->capacity=capacity;
        a=new int[capacity];
    }

    void MinHeapify(int );

    int parent(int i)
    {
    return (i-1)/2;
    }

    int left(int i)
    {
    return (2*i + 1);
    }

    int right(int i)
     {
     return (2*i + 2);
     }

    int extractMin();

    void decreaseKey(int i, int val);


    int getMin()
    {
    return a[0];
    }

    void deleteKey(int i);

    void insertKey(int k);
};




void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }


    heap_size++;
    int i = heap_size - 1;

    a[i] = k;


    while (i != 0 && a[parent(i)] > a[i])
    {
       swap(a[i], a[parent(i)]);
       i = parent(i);
    }
}





void MinHeap::decreaseKey(int i, int val)
{
    a[i] = val;
    while (i != 0 && a[parent(i)] > a[i])
    {
       swap(a[i], a[parent(i)]);
       i = parent(i);
    }
}



int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return a[0];
    }

    int root = a[0];
    a[0] = a[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}


void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}




void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && a[l] < a[i])
        smallest = l;
    if (r < heap_size && a[r] < a[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        MinHeapify(smallest);
    }
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
