#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int merge(int *a, int *left, int l, int *right, int r)
{
    int count = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < l && j < r)
    {
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
        {
            a[k++] = right[j++];
            count += l - i;
        }
    }
    while (i < l)
    {
        a[k++] = left[i++];
    }
    while (j < r)
    {
        a[k++] = right[j++];
    }
    return count;
}
int mergeSort(int *a, int n)
{
    int count = 0;
    if (n < 2)
        return 0;
    int mid = n / 2;
    int *left = new int[mid];
    int *right = new int[n - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = a[i];
    }
    for (int j = mid; j < n; j++)
    {
        right[j - mid] = a[j];
    }
    count += mergeSort(left, mid);
    count += mergeSort(right, n - mid);
    count += merge(a, left, mid, right, n - mid);
    delete[] left;
    delete[] right;
    return count;
}
int countInversion2(int *a, int n)
{
    // O(nlogn)
    return mergeSort(a, n);
}
int countInversion1(int *a, int n)
{
    // O(n^2)

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                count++;
        }
    }
    return count;
}

int countInversion3(int *a, int n)
{
    multiset<int> s;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
        count+=distance(s.upper_bound(a[i]),s.end());
    }
    return count;
}
int main()
{
    // int a[] = {8, 4, 2, 1};
    // int a[] = {1, 2, 3, 4};
    int a[] = {1, 20, 6, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Total Inversions (Brute Force): " << countInversion1(a, n) << endl;
    cout << "Total Inversions (O(n) for space: " << countInversion3(a, n) << endl;
    cout << "Total Inversions (O(nlogn)): " << countInversion2(a, n) << endl;
    return 0;
}


/*

Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already 
sorted, then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the 
maximum. 

*/