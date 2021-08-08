#include<iostream>
#include<algorithm>
using namespace std;
void ThreePartition(int *a,int n,int low,int high)
{
    int start=0,i=0,end=n-1;
    while(i<=end)
    {
        if(a[i]<low)
        {
            swap(a[start++],a[i++]);
        }
        else if(a[i]>high)
        {
            swap(a[i],a[end--]);
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int a[] = {1, 14, 5, 20, 4, 2, 54, 20, 87,98, 3, 1, 32};
    int n = sizeof(a)/sizeof(a[0]);
    ThreePartition(a, n, 10, 20);
    cout << "\nModified array ";
    for (int start=0; start<n; start++)
    {
        cout << a[start] << " ";
    }
    return 0;
}