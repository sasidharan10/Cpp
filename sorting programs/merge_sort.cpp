#include <iostream>
#include <algorithm>
using namespace std;
void merge(int *a,int *left,int l,int *right,int r)
{
    int i=0;
    int j=0;
    int k=0;
    while (i<l && j<r)
    {
        if(left[i]<right[j])
            a[k++]=left[i++];
        else
            a[k++]=right[j++];
    }
    while (i<l)
    {
        a[k++]=left[i++];
    }
    while (j<r)
    {
        a[k++]=right[j++];
    }
}
void mergeSort(int *a,int n)
{
    if(n<2)
        return;
    int mid=n/2;
    int *left = new int[mid];
    int *right = new int[n-mid];
    for (int i = 0; i < mid; i++)
    {
        left[i]=a[i];
    }
    for (int j = mid; j < n; j++)
    {
        right[j-mid]=a[j];
    }
    mergeSort(left,mid);
    mergeSort(right,n-mid);
    merge(a,left,mid,right,n-mid);
    delete []left;
    delete []right;
}
int main()
{
    int a[] = {6, 5, 8, 4, 7, 2, 3, 1,9};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The array is : ";
    for (int i : a)
        cout << i << " ";

    mergeSort(a, n);
    cout << "\nThe Sorted array is : ";
    for (int i : a)
        cout << i << " ";
    return 0;
}