#include<iostream>
using namespace std;
int getmax(int *a, int n)
{
    return (n==1)?a[0]:max(a[0],getmax(a+1,n-1));
}
int main()
{
    int a[] = {21, 23, 56, 65, 34, 54, 76, 32, 23, 45, 21, 23, 25};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"max: "<<getmax(a,n);
    return 0;
}