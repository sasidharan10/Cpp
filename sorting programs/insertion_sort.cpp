#include<iostream>
using namespace std;
void insertion(int arr[],int n)
{
    int hole=0,value=0;
    for(int i=1;i<n;i++)
    {
        value=arr[i];  // to check the current value with other elements
        hole=i;   // after while loop gets terminated, hole will have the index for the current value
        while(hole>0 && arr[hole-1]>value)
        {
            arr[hole]=arr[hole-1];
            hole=hole-1;
        }
        arr[hole]=value;
    }
}
int main()
{
    int arr[]={6,5,8,4,9,7,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The array is : ";
    for(int i:arr)
        cout<<i<<", ";
    insertion(arr,n);
    cout<<"\nThe Sorted array is : ";
    for(int i:arr)
        cout<<i<<", ";
    return 0;
}