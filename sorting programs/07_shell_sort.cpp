#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void shellSort(int *a, int n)
{

    // TC: O(n((logn)^2))
    // SC: O(1)

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // first loop, for calculating gap.
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;

            // performing insertion sort, for the gapped elements.
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}
int main()
{
    int a[] = {12, 34, 54, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    shellSort(a, n);
    cout << "\nThe Sorted array is : ";
    for (int i : a)
        cout << i << " ";
    return 0;
}