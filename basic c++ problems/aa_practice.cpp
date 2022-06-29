#include <iostream>
#include <climits>
using namespace std;
void binary(int *a, int beg, int end, int key)
{
    if (beg <= end)
    {
        int mid = beg + (end - beg) / 2;   // to avoid overflow
        if (a[mid] == key)
        {
            cout << "Element found at index: " << mid;
            return;
        }
        else if (a[mid] < key)
            binary(a, mid + 1, end, key);
        else
            binary(a, beg, mid - 1, key);
    }
    else
    {
        cout << "Not Found!!!";
        return;
    }
}
int main()
{
    int ar[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(ar) / sizeof(ar[0]);
    int x = 9;
    int beg = 0;
    int end = n - 1;
    binary(ar, beg, end, x);
    return 0;
}