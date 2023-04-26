#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
using namespace std;
void kadane(int *a, int n)
{
    int max_so_far=INT_MIN;
    int max_here=0;
    int s=0, start=0, end=0;
    for (int i = 0; i < n; i++)
    {
        max_here+=a[i];
        if(max_here>max_so_far)
        {
            max_so_far=max_here;
            start=s;
            end=i;
        }
        if(max_here<0)
        {
            max_here=0;
            s=i+1;
        }
    }
    cout << "Max Sum of Sub-Array is (kadane algorithm) : " << max_so_far << endl;
    cout << "Sub-Array is : ";
    for (int i = start; i <= end; i++)
    {
        cout << a[i] << " ";
    }
    
}
int main()
{
    int a[]{-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    kadane(a,n);

    return 0;
}