#include <iostream>
#include <algorithm>
using namespace std;
void common(int *a, int *b, int *c, int n1, int n2, int n3)
{
    cout << "Common are : ";
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            cout << a[i] << " ";
            i++;
            j++;
            k++;
        }
        else if (a[i] < b[j])
            i++;
        else if (b[j] < c[k])
            j++;
        else
            k++;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 6, 7, 8, 9};
    int b[] = {2, 4, 6, 6, 8};
    int c[] = {1, 3, 4, 6, 6, 7, 9};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int n3 = sizeof(c) / sizeof(c[0]);
    common(a, b, c, n1, n2, n3);
    return 0;
}