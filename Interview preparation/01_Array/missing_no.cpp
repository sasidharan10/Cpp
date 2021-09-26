#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[] = {1, 2, 4, 6, 3, 7, 8, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int sum1=((n+1)*(n+2)/2);
    // n=n+1 as we have to include the missing number also
    for (int i = 0; i < n; i++)
    {
        sum1-=a[i];
    }
    // to prevent overflow
    int sum2=1;
    for (int i = 2; i <= n+1; i++)
    {
        sum2+=i;
        sum2-=a[i-2];
    }
    cout << "Missing is : "<<sum1;
    cout << "\nMissing is : "<<sum2;
    return 0;
}