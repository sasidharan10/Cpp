#include <iostream>
using namespace std;
void bub_sort(int arr[], int n)
{
    int temp = 0, flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {6, 5, 8, 4, 9, 7, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The array is : ";
    for (int i : arr)
        cout << i << ", ";
    bub_sort(arr, n);
    cout << "\nThe Sorted array is : ";
    for (int i : arr)
        cout << i << ", ";
    return 0;
}

// for first loop (n-1) passes is enough because at last loop it will check the first element with the second
// element which is not needed as all greater elements are already pushed int hat array.array gets sorted at (n-1)
// passes itself