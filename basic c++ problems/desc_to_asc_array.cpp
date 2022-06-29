#include <iostream>
#include <algorithm>
using namespace std;
void changeOrder(int *a, int n)
{
    // for (int i = 0; i < n / 2; i++)
    // {
    //     swap(a[i], a[n - i - 1]);
    // }
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}
int main()
{
    int a[]{7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    changeOrder(a, n);
    cout << "Array : ";
    for (int i : a)
    {
        cout << i << " ";
    }
    return 0;
}