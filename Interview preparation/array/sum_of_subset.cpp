#include<iostream>
#include<algorithm>
using namespace std;
bool sum_of_subset(int *a,int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum=0;
        for (int j = i; j < n; j++)
        {
            sum+=a[j];
            if(sum==0)
                return true;
        }
        
    }
    return false;
}
int main()
{
    int a[] = {-3, 2, 3, 1, 6};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<sum_of_subset(a, n);
    return 0;
}