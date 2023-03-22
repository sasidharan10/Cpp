#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int compareInt(const void *a, const void *b)
{
    const int *p1 = (int *)a;
    const int *p2 = (int *)b;
    return *p1 - *p2;
}
int main()
{
    int arr[] = {3, 2, 6, 8, 4, 1, 7, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, sizeof(arr), sizeof(int), compareInt);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}