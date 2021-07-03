#include<iostream>
#include<algorithm>
using namespace std;
void segregate1(int *a,int n)
{
    int c0=0,c1=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==0)
            c0++;
        if(a[i]==1)
            c1++;
    }
    int i=0;
    while (c0>0)
    {
        a[i++]=0;
        c0--;
    }
    while (c1>0)
    {
        a[i++]=1;
        c1--;
    }
    while (n>i)
    {
        a[i++]=2;
    }
    cout<<"\nSorted array(method 1): ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }  
}
void segregate2(int *a,int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(a[mid]==0)
            swap(a[mid++],a[low++]);
        if(a[mid]==1)
            mid++;
        if(a[mid]==2)
            swap(a[mid],a[high--]);
    }
    cout<<"\nSorted array(method 2) : ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    segregate1(arr,n);
    segregate2(arr,n);
    return 0;
}

// Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.