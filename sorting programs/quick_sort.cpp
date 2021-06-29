#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int start,int end)
{
    int p_index=start;  
    int pivot=a[end];  // taking last element as pivot element
    for(int i = start; i < end; i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[p_index]);
            p_index++;
        }
    }
    swap(a[p_index],a[end]);  // swapping the pivot element in its appropriate index
    return p_index;
}
void quick_sort(int a[],int start,int end)
{
    if(start>=end)
        return;
    int p_index= partition(a,start,end);
    quick_sort(a,start,p_index-1);   //array left to pivot element
    quick_sort(a,p_index+1,end);     //array right to pivot element
}

int main()
{
    int a[]={6,5,8,4,7,2,3,1};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"The array is : ";
    for(int i:a)
        cout<<i<<", ";

    quick_sort(a,0,n-1);
    
    cout<<"\nThe Sorted array is : ";
    for(int i:a)
        cout<<i<<", ";
    return 0;
}