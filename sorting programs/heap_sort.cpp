#include <iostream>
#include <algorithm>
using namespace std;
void heapify(int *a, int i, int n)
{
    // Time : O(nlogn)
    // Space : O(1)

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
        heapify(a, largest, n);
    }
}
void heapsort(int *a, int n)
{
    // build heap - O(n)
    int start = (n / 2) - 1;
    for (int i = start; i >= 0; i--)
    {
        heapify(a, i, n);
    }
    for (int i = n - 1; i > 0; i--) //loop runs till n-1 to 1. No need to swap last element(already sorted)
    {
        swap(a[0], a[i]); // swapping the max element(root) with last element
        heapify(a, 0, i); // heapify all element except last one
    }
    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[] = {6, 5, 8, 4, 9, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    heapsort(a, n); // using max heap
    return 0;
}