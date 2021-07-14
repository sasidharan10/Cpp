#include <iostream>
#include <algorithm>
using namespace std;
void findTriplet(int *a, int n, int k)
{
    sort(a,a+n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i+1;
        int r = n - 1;
        sum = k - a[i];
        while (l < r)
        {
            if (a[l]+a[r]==sum)
            {
                cout<<"The triplet is : ";
                cout<<a[i]<<" "<<a[l]<<" "<<a[r];
                return;
            }
            else if(a[l]+a[r]<sum)
                l++;
            else
                r--;
        }
    }
    cout<<"Sum not found!!!"<<endl;
}
int main()
{
    int a[] = {1, 3, 6, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 10;
    findTriplet(a, n, k);
    return 0;
}