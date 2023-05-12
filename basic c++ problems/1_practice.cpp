#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int count=0;
void merge(int *a,int *left,int l,int *right,int r, vector<int>&ans)
{
    // Time  : O(n*logn)
    // Space : O(n)

    int i=0;
    int j=0;
    int k=0;
    while (i<l && j<r)
    {
        if(left[i]<right[j])
        {
            a[k++]=left[i++];
        }
        else
        {
            ans.push_back(l-i);
            a[k++]=right[j++];
        }
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
void mergeSort(int *a,int n, vector<int>&ans)
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
    mergeSort(left,mid, ans);
    mergeSort(right,n-mid, ans);
    merge(a,left,mid,right,n-mid, ans);
    delete []left;
    delete []right;
}
int main()
{
    // int a[] = {6, 5, 8, 4, 7, 2, 3, 1,9};
    int a[] = {5, 2, 6, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The array is : ";
    for (int i : a)
        cout << i << " ";
    vector<int>ans;
    mergeSort(a, n, ans);
    cout<<ans.size()<<endl;
    for (int i = ans.size(); i < n; i++)
    {
        ans.push_back(0);
    }
    
    cout << "\nThe Sorted array is : ";
    for (int i : ans)
        cout << i << " ";
    return 0;
}



/*

Here we divide the array by 2, untill we get a array of size 1, which is sorted by itself
now we join the divided array in sorted order, and eventually the array gets sorted.


*/