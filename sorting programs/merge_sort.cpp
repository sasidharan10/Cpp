#include <iostream>
#include <algorithm>
using namespace std;
void merge(int *a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int *left = new int[mid];      
    int *right = new int[r - mid];
    // int left[mid];
    // int right[r - mid];
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = a[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    while (i < n1)
    {
        a[k++] = left[i++];
    }
    while (j < n2)
    {
        a[k++] = right[j++];
    }
    delete[] left;
    delete[] right;
}
void mergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);       // left array
        mergeSort(a, mid + 1, r);   // right array
        merge(a, l, mid, r);        // merging both array
    }
}
int main()
{
    int a[] = {6, 5, 8, 4, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The array is : ";
    for (int i : a)
        cout << i << ", ";

    mergeSort(a, 0, n - 1);
    cout << "\nThe Sorted array is : ";
    for (int i : a)
        cout << i << ", ";
    return 0;
}