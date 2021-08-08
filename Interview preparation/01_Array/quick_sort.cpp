#include <iostream>
#include <algorithm>
using namespace std;
int partition(int *a, int start, int end)
{
    int pivot = a[end]; // end element as pivot
    int p_index = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[p_index]);
            p_index++;
        }
    }
    swap(a[end], a[p_index]);
    return p_index;
}
void quick_sort(int *a, int start, int end)
{
    if (start < end)
    {
        int p_index = partition(a, start, end);
        quick_sort(a, start, p_index - 1);
        quick_sort(a, p_index + 1, end);
    }
    return;
}
int main()
{
    int a[] = {6, 5, 1, 4, 7, 10, 2, 8};
    int n = sizeof(a) / sizeof(a[0]);
    quick_sort(a, 0, n - 1);
    cout << "Sorted array is : ";
    for (int i : a)
        cout << i << " ";
    return 0;
}