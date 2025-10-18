#include <iostream>
using namespace std;
void insertion(int arr[], int n)
{
    // Time  : O(n^2)
    // Space : O(1)

    int hole = 0, value = 0;
    for (int i = 1; i < n; i++)
    {
        value = arr[i]; // to check the current value with other elements
        hole = i;       // after while loop gets terminated, "hole" will have the index for the current value
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole = hole - 1;
        }
        arr[hole] = value;
    }
}
int main()
{
    int arr[] = {6, 5, 8, 4, 9, 7, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The array is : ";
    for (int i : arr)
        cout << i << " ";
    insertion(arr, n);
    cout << "\nThe Sorted array is : ";
    for (int i : arr)
        cout << i << " ";
    return 0;
}

/*

Algorithm

- here we iterate the array and sort the left side of array as we move forward.
  the shorter elements are sorted and pushed on the left.


*/