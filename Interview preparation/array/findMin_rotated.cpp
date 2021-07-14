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
    int arr1[] = {5, 6, 1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "The minimum element is " << FindTargetRotatedArray(arr1, n1) << endl;
 
    int arr2[] = {1, 2, 3, 4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << "The minimum element is " << FindTargetRotatedArray(arr2,  n2) << endl;
 
    int arr3[] = {1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    cout<<"The minimum element is "<<FindTargetRotatedArray(arr3, n3)<<endl;
 
    int arr4[] = {1, 2};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    cout<<"The minimum element is "<<FindTargetRotatedArray(arr4, n4)<<endl;
 
    int arr5[] = {2, 1};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    cout<<"The minimum element is "<<FindTargetRotatedArray(arr5, n5)<<endl;
 
    int arr6[] = {5, 6, 7, 1, 2, 3, 4};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    cout<<"The minimum element is "<<FindTargetRotatedArray(arr6,  n6)<<endl;
 
    int arr7[] = {1, 2, 3, 4, 5, 6, 7};
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    cout << "The minimum element is " << FindTargetRotatedArray(arr7, n7) << endl;
 
    int arr8[] = {2, 3, 4, 5, 6, 7, 8, 1};
    int n8 = sizeof(arr8)/sizeof(arr8[0]);
    cout << "The minimum element is " << FindTargetRotatedArray(arr8, n8) << endl;
 
    int arr9[] = {7,8,1,2,3,4,5};
    int n9 = sizeof(arr9)/sizeof(arr9[0]);
    cout << "The minimum element is " << FindTargetRotatedArray(arr9, n9) << endl;
}