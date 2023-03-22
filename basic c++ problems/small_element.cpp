#include <iostream>
using namespace std;
void small(int a[], int n)
{
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    cout << "\nmin is : " << min << endl;
}
int main()
{
    int a[] = {11, 6, 5, 9, 8, 3, 2, 4, 7};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "The array is : ";
    for (int i : a)
        cout << i << ", ";

    small(a, n);
    return 0;
}