#include <iostream>
#include <algorithm>
using namespace std;
void changeOrder(int *a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - i - 1]);
    }
}
int main()
{
    int a[]{6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    changeOrder(a, n);
    cout << "Array : ";
    for (int i : a)
    {
        cout << i << " ";
    }
    return 0;
}