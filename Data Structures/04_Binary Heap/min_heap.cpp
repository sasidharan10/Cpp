#include <iostream>
#include <algorithm>
using namespace std;
void minHeapify(int *a, int i, int n)
{
    // Time : O(logn)

    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int smallest = i;
    if (left < n && a[left] < a[i])
        smallest = left;
    if (right < n && a[right] < a[smallest])
        smallest = right;
    if (i != smallest) // checking, if a[i] is smallest, if yes, then no need to heapify further
    {
        swap(a[i], a[smallest]);
        minHeapify(a, smallest, n);
    }
}
void buildHeap(int *a, int n)
{
    // Time : O(nlogn)
    // Space : O(1)

    // i=(n / 2) - 1) since, we can heapify fro internal nodes
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        minHeapify(a, i, n);
    }
    cout<<a[1]<<endl;
    cout << "Min Heap : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[] = {6, 5, 8, 4, 9, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    buildHeap(a, n);
    return 0;
}

/*

- Heapify: a process of rearranging the heap by comparing each parent, with
  its children node recursively is known as heapify.
- In Min-heap, insertion - O(logn), find_min - O(1), del_min - O(logn) is optimised
  compared to other data structure.
- In a binary tree of 'n' nodes, there will be (n/2)-1 internal nodes.
  We will heapify from the internal nodes, since leaf nodes doesn't have any child nodes.


*/