#include <iostream>
#include <climits>
using namespace std;
int recur(int *arr, int beg, int end, int x)
{
    if (beg <= end)
    {
        int mid = beg + (end - beg)  / 2;
        if (arr[mid] == x)
            return mid;
        if (x > arr[mid])
            return recur(arr, mid + 1, end, x);
        if (x < arr[mid])
            return recur(arr, beg, mid - 1, x);
    }
    return -1;
}
int Binary_search(int *arr, int n, int x)
{
    int mid = 0, beg = 0, end = n - 1;
    return recur(arr, 0, end, x);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int ans = Binary_search(arr, n, x);
    // int ans=recur(arr,0,n-1,x);
    if (ans != -1)
        cout << "Found at index: " << ans << endl;
    else
        cout << "Not Found!!! " << endl;
    return 0;
}