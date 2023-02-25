#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
class heap
{
public:
    int *a;            // heap array
    int capacity;      // capacity of heap (static)
    int heap_size = 0; // size of heap (it gets updated)

    // functions :

    heap(int cap) // getting the capacity od heap from user
    {
        capacity = cap;
        a = new int[cap]; // array created dynammically
    }

    int parent(int i) { return (i - 1) / 2; } // index of parent
    int left(int i) { return (2 * i) + 1; }   // index of left child
    int right(int i) { return (2 * i) + 2; }  // index of right child

    void heapify(int i)
    {
        int l = left(i);  // left child index
        int r = right(i); // right child index
        int smallest = i;
        if (l < heap_size && a[l] < a[i]) // if left child is smaller, it is updated
            smallest = l;
        if (r < heap_size && a[r] < a[smallest]) // vice-versa
            smallest = r;
        if (smallest != i) // if any child is smaller, swap it
        {
            swap(a[i], a[smallest]);
            heapify(smallest); // again calling the fn() to check its child
        }
    }

    void Insert(int key) // inserting a new element and heapify it
    {
        if (heap_size == capacity) // if heap is full, return error
        {
            cout << "Heap overflow!!!" << endl;
            return;
        }
        heap_size++;                          // increase heap size
        int i = heap_size - 1;                // index of last node
        a[i] = key;                           // adding the key in last node
        while (i != 0 && a[parent(i)] > a[i]) // if key is smaller than its parent, swap it
        {
            swap(a[parent(i)], a[i]);
            i = parent(i); // update the index value
        }
    }
    int extractMin() // removing top element and returning it
    {
        if (heap_size <= 0) // checking if heap is empty
        {
            cout << "Heap is Empty()!!!" << endl;
        }
        if (heap_size == 1) // if only 1 element present
        {
            heap_size--;
            return a[0];
        }
        int root = a[0];         // keeping top(min) to return it
        a[0] = a[heap_size - 1]; // swapping the last element to top
        heap_size--;             // size decreases
        heapify(0);              // heapify the tree
        return root;             // return the min
    }
    void Delete(int index) // deleting a element by given index
    {
        decreaseKey(index, INT_MIN); // moving the given element to top
        extractMin();                // now removing the top element
    }
    void decreaseKey(int i, int new_val)
    {
        a[i] = new_val;                       // new_val is dummy value
        while (i != 0 && a[i] < a[parent(i)]) // this will move the element to top
        {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    bool linearSearch(int key) // searching the element
    {
        if (heap_size == 0)
            cout << "Heap is Empty()!!!" << endl;
        for (int i = 0; i < heap_size; i++)
        {
            if (a[i] == key)
                return true;
        }
        return false;
    }
    int getMin()  // returning top element
    {
        if (heap_size == 0)
            cout << "Heap is Empty()!!!" << endl;
        return a[0];
    }
    int height()  // returning height
    {
        return ceil(log2(heap_size + 1)) - 1;
    }
    void printHeap() // printing the heap
    {
        if (heap_size == 0)
            cout << "Heap is Empty()!!!" << endl;
        cout << "Min Heap : ";
        for (int i = 0; i < heap_size; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
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
    if (h.linearSearch(20))
        cout << "Element Found" << endl;
    else
        cout << "Element Not Found!!!" << endl;
    cout << "Top : " << h.extractMin() << endl;
    cout << "Top : " << h.getMin() << endl;
    cout << "Height : " << h.height() << endl;
    h.printHeap();
    h.Delete(3);
    h.printHeap();
    return 0;
}

/*
          5
       /    \
      15     10
     /  \    /
    25  20  18


*/