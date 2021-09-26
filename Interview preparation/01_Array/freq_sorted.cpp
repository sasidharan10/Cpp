#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={1,2,2,2,3,3,4,5,6,6,6,6,6,7,7,8,9,9};
    int n = sizeof(a) / sizeof(a[0]);
    int k=6;
    auto p=lower_bound(a,a+n,k);
    auto q=upper_bound(a,a+n,k);
    cout<<"Frequency of "<<k<<" is : "<<q-p;
}