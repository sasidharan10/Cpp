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
    if (i != smallest)
    {
        swap(a[i], a[smallest]);
        minHeapify(a, smallest, n);
    }
}
void buildHeap(int *a, int n)
{
    // Time : O(nlogn)
    // Space : O(1)

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        minHeapify(a, i, n);
    }
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