#include <iostream>
#include <algorithm>
using namespace std;
int partition(int a[], int start, int end)
{
    // Time  : O(n^2)
    // Space : O(n)

    int p_index = start;
    int pivot = a[end];               // taking last element as pivot element
    for (int i = start; i < end; i++) // 0 to n-1 (excluding last element)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[p_index]);
            p_index++;
        }
    }
    // left of p_index will have lesser value than pivot and higher in right side
    swap(a[p_index], a[end]); // swapping the pivot element in its appropriate index
    return p_index;
}
void quick_sort(int a[], int start, int end)
{
    if (start >= end)
        return;
    int p_index = partition(a, start, end);
    quick_sort(a, start, p_index - 1); //array left to pivot element
    quick_sort(a, p_index + 1, end);   //array right to pivot element
}

int main()
{
    int a[] = {6, 5, 8, 4, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The array is : ";
    for (int i : a)
        cout << i << " ";

    quick_sort(a, 0, n - 1);

    cout << "\nThe Sorted array is : ";
    for (int i : a)
        cout << i << " ";
    return 0;
}


/*

- We take a pivot element, mostly first or last element.
- then we traverse the whole array, and place the pivot element in its apropriate position.
- then, we send the left array to pivot, and then to the right. after every call, each element
  is placed it its sorted position.


*/


/*   
************* Java Code **************

public static void quickSort(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return;
        }
        quickSort(arr, 0, arr.length - 1);
    }

    private static void quickSort(int[] arr, int start, int end) {
        if (start >= end) {
            return;
        }
        int p_index = partition(arr, start, end);
        quickSort(arr, start, p_index - 1); // array left to pivot element
        quickSort(arr, p_index + 1, end);   // array right to pivot element
    }

    private static int partition(int[] arr, int start, int end) {
        // Time  : O(n^2) worst case, O(n log n) average case
        // Space : O(log n) due to recursion stack

        int p_index = start;
        int pivot = arr[end];               // taking last element as pivot element
        
        for (int i = start; i < end; i++) { // start to end-1 (excluding last element)
            if (arr[i] <= pivot) {
                swap(arr, i, p_index);
                p_index++;
            }
        }
        // left of p_index will have lesser value than pivot and higher in right side
        swap(arr, p_index, end); // swapping the pivot element in its appropriate index
        return p_index;
    }

*/