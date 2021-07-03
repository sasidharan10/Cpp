#include<iostream>
using namespace std;
void sel_sort(int arr[], int n)
{
    int min=0,temp=0;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
int main()
{
    int n;
    int arr[]={2,3,6,1,4,9,5,8,7};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<"The array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    sel_sort(arr,n);
    cout<<"\nThe sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
/*

algorithm :

The selection sort algorithm sorts an array by repeatedly finding the minimum element from unsorted part and putting it at the beginning.

*/