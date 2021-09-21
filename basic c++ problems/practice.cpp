#include<iostream>
#include<algorithm>
using namespace std;
void leftrotate(int *a,int n)
{
    int i=0,j=n-1;
    while (i!=j)
    {
        swap(a[i],a[j]);
        j--;
    }
    
}
void rightrotate(int *a,int n)
{
    int i=0,j=n-1;
    while (i!=j)
    {
        swap(a[i],a[j]);
        i++;
    }
}
int main()
{
    int a[]{1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    leftrotate(a,n);
    cout<<"\nLeft rotate : ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    rightrotate(a,n);
    cout<<"\nRight rotate : ";
        for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}