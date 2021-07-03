#include<iostream>
using namespace std;
void insertion(int arr[],int n)
{
    int index=0,value=0;
    for(int i=1;i<n;i++)
    {
        value=arr[i];  // to check the current value with other elements
        index=i;   // after while loop gets terminated, "index" will have the index for the current value
        while(index>0 && arr[index-1]>value)
        {
            arr[index]=arr[index-1];
            index=index-1;
        }
        arr[index]=value;
    }
}
int main()
{
    int arr[]={6,5,8,4,9,7,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The array is : ";
    for(int i:arr)
        cout<<i<<" ";
    insertion(arr,n);
    cout<<"\nThe Sorted array is : ";
    for(int i:arr)
        cout<<i<<" ";
    return 0;
}

// Algorithm

// here we iterate the array and sort the left side of array as we move forward. the shorter elements the sorted and pushed on the left.