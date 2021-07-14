#include <iostream>
#include <algorithm>
using namespace std;
bool FindTargetRotatedArray(int *a, int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
            return true;
        else if (a[mid] >= a[low]) // left sub-array is sorted
        {
            if (target >= a[low] && target <= a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else // right sub-array is sorted
        {
            if (target >= a[mid] && target <= a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}
int main()
{
    int a[] = {5, 6, 1, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 4;
    if (FindTargetRotatedArray(a, n, target))
        cout << "Element Found :) " << endl;
    else
        cout << "Element Not Found :() " << endl;
    return 0;
}