#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int kthSmallest(int arr[], int n, int k)
{
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = arr[i];
    }
    sort(b, b + n);
    // cout << "Array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    return b[k - 1];
}
int kth_element1(int *a, int n, int k)
{
    // Time  : O(n^2)
    // Space : O(1)

    int min, temp;
    // bubble sort
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
int kth_element2(int *a, int n, int k)
{
    priority_queue<int> p(a, a + n); // max heap by default
    for (int i = 0; i < k - 1; i++)
    {
        p.pop();
    }
    return p.top();
    //
}
int quickSelect(int *a, int start, int end, int k)
{
    // Time : O(n^2) but O(n) on average as worst case is almost avoidable
    // Space : O(1)

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

int main()
{
    int a[] = {6, 5, 8, 4, 9, 7, 2, 3, 1, 10};
    // int a[] = {6, 5, 1,3,2,4};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    cout << k << "th Smallest Element (sort function): " << kthSmallest(a, n, k) << endl;
    cout << k << "th Smallest Element (sorting): " << kth_element1(a, n, k) << endl;
    cout << k << "th Largest Element (sorting): " << kth_element1(a, n, n - k + 1) << endl;
    cout << k << "th Smallest Element (Heap): " << kth_element2(a, n, k) << endl;
    cout << k << "th Largest Element (Heap): " << kth_element2(a, n, n - k + 1) << endl;
    cout << k << "th Smallest Element (QuickSelect) : " << quickSelect(a, 0, n - 1, k) << endl;
    cout << k << "th Largest Element (QuickSelect) : " << quickSelect(a, 0, n - 1, n - k + 1) << endl;
    // return 0;
}
/*

 Given an array and a number k where k is smaller than the size of the array, we need to find the k’th
 smallest element in the given array. It is given that all array elements are distinct.

 link: https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array/

 leetcode: https://leetcode.com/problems/kth-largest-element-in-an-array/

*/