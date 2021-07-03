#include <iostream>
#include <algorithm>
using namespace std;
int kth_element(int *a, int n, int k)
{
    int min, temp;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    return a[k - 1];
    // return a[n-k]; // for kth biggest element
}
int main()
{
    int a[] = {6, 5, 8, 4, 9, 10, 7, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    cout << k << "th smallest Element : " << kth_element(a, n, k);
    return 0;
}

// Given an array and a number k where k is smaller than the size of the array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.