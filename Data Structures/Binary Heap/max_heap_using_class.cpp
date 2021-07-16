#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class heap
{
public:
    int *a;
    int capacity;
    int heap_size = 0;

    // functions

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i) + 1; }
    int right(int i) { return (2 * i) + 2; }

    heap(int cap)
    {
        capacity = cap;
        a = new int[cap]; // array dynamically created
    }
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heap_size && a[i] < a[l])
            largest = l;
        if (r < heap_size && a[largest] < a[r])
            largest = r;
        if (i != largest)
        {
            swap(a[i], a[largest]);
            heapify(largest);
        }
    }
    int top()
    {
        if (heap_size <= 0)
        {
            cout << "Heap is Empty!!!" << endl;
            return -1;
        }
        return a[0];
    }
    void pop()
    {
        if (heap_size <= 0)
        {
            cout << "Heap is Empty!!!" << endl;
            return;
        }
        if (heap_size == 1)
        {
            heap_size--;
        }
        a[0] = a[heap_size - 1];
        heap_size--;
        heapify(0);
    }
    void Insert(int key)
    {
        // O(nlogn) for building
        if (heap_size == capacity)
        {
            cout<<"Heap Overflow!!!"<<endl;
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        a[i] = key;
        while (i != 0 && a[i] > a[parent(i)])
        {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    void printHeap() // printing the heap
    {
        if (heap_size == 0)
            cout << "Heap is Empty!!!" << endl;
        cout << "Max Heap : ";
        for (int i = 0; i < heap_size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    int height() // returning height
    {
        return ceil(log2(heap_size + 1)) - 1;
    }
};
int main()
{
    heap h(20); // setting the capacity as 20
    h.Insert(10);
    h.Insert(25);
    h.Insert(5);
    h.Insert(15);
    h.Insert(20);
    h.Insert(18);
    h.printHeap();
    cout << "Top : " << h.top() << endl;
    cout << "Height : " << h.height() << endl;
    h.printHeap();
    h.pop();
    h.printHeap();
    return 0;
}
