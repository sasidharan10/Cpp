#include <iostream>
#include <algorithm>
using namespace std;
void maxHeapify(int *a, int i, int n)
{
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int largest = i;
    if (left < n && a[i] < a[left])
        largest = left;
    if (right < n && a[largest] < a[right])
        largest = right;
    if (i != largest)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, largest, n);
    }
}
void buildHeap(int *a, int n)
{
    int start = (n / 2) - 1;   // heapifying internal nodes are sufficient
    for (int i = start; i >= 0; i--)
    {
        maxHeapify(a, i, n);
    }
    cout << "Max Heap : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    // O(n) for build heap
    int a[] = {6, 5, 8, 4, 9, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    buildHeap(a, n);
    return 0;
}