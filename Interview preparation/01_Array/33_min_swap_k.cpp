#include <iostream>
#include <algorithm>
using namespace std;
int minSwap(int *a, int n, int k)
{
    int i = 0, j = n - 1;
    int count = 0;
    while (i <= j)
    {
        if (a[i] < k)
        {
            i++;
            j--;
        }  
        else  
        {
            count++;
            i++;
            j--;
        }
    }
    return count;
}
int main()
{
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << "Min Swap : " << minSwap(arr, n, k);
}