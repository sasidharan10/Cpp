#include<iostream>
#include<algorithm>
using namespace std;
void minAndMax(int *a,int n)
{
    int max=0,min=a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
    cout<<"Max : "<<max<<endl;
    cout<<"Min : "<<min<<endl;

    // using library function

    cout<<"Max using library: "<<*max_element(a,a+n)<<endl;
    cout<<"Min using library: "<<*min_element(a,a+n)<<endl;
}
int getMax(int *a,int n)
{
    return (n==1)?a[0]:max(a[0],getMax(a+1,n-1));
}
int getMin(int *a,int n)
{
    return (n==1)?a[0]:min(a[0],getMin(a+1,n-1));
}
int main()
{
    int a[] = { 21, 23, 56, 65, 34, 54, 76, 32, 23, 45, 21, 23, 25};
    int n=sizeof(a)/sizeof(a[0]);
    // minAndMax(a,n);
    cout<<"Max using recursion : "<<getMax(a,n)<<endl;
    cout<<"Min using recursion : "<<getMin(a,n)<<endl;
    return 0;
}

// Program to find the minimum and maximum element of an array