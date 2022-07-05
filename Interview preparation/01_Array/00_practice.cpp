#include<iostream>
#include<algorithm>
using namespace std;
int getMax(int *a, int n)
{
    if(n==1)
        return a[0];
    return max(a[0],getMax(a+1,n-1));
}
int getMin(int *a, int n)
{
    if(n==1)
        return a[0];
    return min(a[0],getMin(a+1,n-1));
}
int main()
{
    int a[]{5,3,2,1,6,4};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"Max: "<<getMax(a,n)<<endl;
    cout<<"Min: "<<getMin(a,n)<<endl;
    return 0;
}