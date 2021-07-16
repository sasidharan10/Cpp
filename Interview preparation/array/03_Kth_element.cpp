#include <iostream>
#include <algorithm>
using namespace std;
int kth_element(int *a, int n, int k)
{
    // bubble sort (O(nlogn))
    int min, temp;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    return a[k - 1];
    // return a[n-k]; // for kth biggest element
}
int partition(int *a, int start, int end)
{
    int pivot = a[end];
    int p_index = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[p_index]);
            p_index++;
        }
    }
    swap(a[p_index], a[end]);
    return p_index;
}
int quickSelect(int *a, int start, int end, int k)
{
    if (start <= end)
    {
        int p_index = partition(a, start, end);
        if (p_index == k - 1)
            return a[p_index];
        else if (p_index > k - 1)
            return quickSelect(a, start, p_index - 1, k);
        else if (p_index < k - 1)
            return quickSelect(a, p_index + 1, end, k);
    }
    return -1;
}
int main()
{
    int a[] = {6, 5, 8, 4, 9, 10, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    cout << k << "th Smallest Element : " << kth_element(a, n, k) << endl;
    cout << k << "th Largest Element : " << kth_element(a, n, n - k + 1) << endl;
    cout << k << "th Smallest Element (QuickSelect) : " << quickSelect(a, 0, n - 1, k) << endl;
    cout << k << "th Largest Element (QuickSelect) : " << quickSelect(a, 0, n - 1, n - k + 1) << endl;
    return 0;
}
/*

 Given an array and a number k where k is smaller than the size of the array, we need to find the k’th 
 smallest element in the given array. It is given that all array elements are distinct.

*/