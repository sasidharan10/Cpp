#include <iostream>
#include <algorithm>
using namespace std;
void merge(int *a, int *left, int l, int *right, int r)
{
    // Time  : O(n*logn)
    // Space : O(n)

    int i = 0;
    int j = 0;
    int k = 0;
    while (i < l && j < r)
    {
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    while (i < l)
    {
        a[k++] = left[i++];
    }
    while (j < r)
    {
        a[k++] = right[j++];
    }
}
void mergeSort(int *a, int n)
{
    if (n < 2)
        return;
    int mid = n / 2;
    int *left = new int[mid];
    int *right = new int[n - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = a[i];
    }
    for (int j = mid; j < n; j++)
    {
        right[j - mid] = a[j];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(a, left, mid, right, n - mid);
    delete[] left;
    delete[] right;
}
int main()
{
    // int a[] = {6, 5, 8, 4, 7, 2, 3, 1, 9};
    int a[] = {6, 5, 8, 3, 1, 9};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The array is : ";
    for (int i : a)
        cout << i << " ";

    mergeSort(a, n);
    cout << "\nThe Sorted array is : ";
    for (int i : a)
        cout << i << " ";
    return 0;
}

/*

Here we divide the array by 2, untill we get a array of size 1, which is sorted by itself
now we join the divided array in sorted order, and eventually the array gets sorted.

*/

/*
************* Java Code **************

    private static void mergeSort(int[] a, int n) {
        if (n < 2) {
            return;
        }
        
        int mid = n / 2;
        int[] left = new int[mid];
        int[] right = new int[n - mid];
        
        // Copy elements to left array
        for (int i = 0; i < mid; i++) {
            left[i] = a[i];
        }
        
        // Copy elements to right array
        for (int j = mid; j < n; j++) {
            right[j - mid] = a[j];
        }
        
        // Recursively sort both halves
        mergeSort(left, mid);
        mergeSort(right, n - mid);
        
        // Merge the sorted halves
        merge(a, left, mid, right, n - mid);
        
        // Note: In Java, we don't need to manually delete arrays
        // The garbage collector will handle memory management
    }

    private static void merge(int[] a, int[] left, int l, int[] right, int r) {
        // Time  : O(n*logn)
        // Space : O(n)

        int i = 0; // Index for left array
        int j = 0; // Index for right array
        int k = 0; // Index for merged array
        
        // Merge while both arrays have elements
        while (i < l && j < r) {
            if (left[i] < right[j]) {
                a[k++] = left[i++];
            } else {
                a[k++] = right[j++];
            }
        }
        
        // Copy remaining elements from left array
        while (i < l) {
            a[k++] = left[i++];
        }
        
        // Copy remaining elements from right array
        while (j < r) {
            a[k++] = right[j++];
        }
    }


*/