#include<iostream>
#include<algorithm>
using namespace std;
void segregate(int *a,int n)
{
    int low=0;
    int high=n-1;
    while(low<high)
    {
        if(a[low]==0)
            low++;
        else if(a[high]==1)
            high--;
        else
            swap(a[low++],a[high--]);
    }
    cout<<"\nSorted array(method 2) : ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 1, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    segregate(arr,n);
    return 0;
}

// Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.