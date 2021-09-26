#include <iostream>
#include <algorithm>
using namespace std;
int FindTargetRotatedArray(int *arr, int n)
{
    int low = 0;
    int high = n - 1;
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] == arr[high])
            high--;
        else if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[high];
}
int main()
{
    int a[] = {5, 6, 1, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Minimum : " << FindTargetRotatedArray(a, n)<<endl;
    int arr1[] = {7,8,0,1,2,3,4,5,6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "The minimum element is " << FindTargetRotatedArray(arr1, n1) << endl;
    return 0;
}