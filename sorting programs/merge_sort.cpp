#include<iostream>
using namespace std;
void merge(int *left,int *right,int *a,int l,int r)
{
    int i=0;  // index for left array
    int j=0;  // index for right array
    int k=0;  // index for array 'a'

    while(i<l && j<r)
    {
        if(left[i]<right[j])
        {
            a[k++]=left[i++];
        }
        else{
            a[k++]=right[j++];
        }
    }
    while(i<l)
    {
        a[k++]=left[i++];
    }
     while(j<r)
    {
        a[k++]=right[j++];
    }
}
void merge_sort(int a[],int n)
{
    int mid;
    if(n<2)
        return;
    mid=n/2;
    int *left=new int[mid];
    int *right=new int[n-mid];
    for (int i = 0; i < mid; i++)
    {
        left[i]=a[i];
    }
    for (int j = mid; j < n; j++)
    {
        left[j-mid]=a[j];
    }
    merge_sort(left,mid);
    merge_sort(right,n-mid);
    merge(left,right,a,mid,n-mid);
    delete []left;
    delete []right;
}

int main()
{
    int a[]={6,5,8,4,7,2,3,1};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"The array is : ";
    for(int i:a)
        cout<<i<<", ";

    merge_sort(a,n);
    
    cout<<"\nThe Sorted array is : ";
    for(int i:a)
        cout<<i<<", ";
    return 0;
}