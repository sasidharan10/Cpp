#include <iostream>
#include <algorithm>
using namespace std;

int Binary_search(int *a, int key, int beg, int end)
{
    if (beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
            return Binary_search(a, key, mid + 1, end);
        if (a[mid] > key)
            return Binary_search(a, key, beg, mid - 1);
    }
    return -1;
}

int main()
{
    int a[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 3;
    int x = Binary_search(a, key, 0, n - 1);
    if (x == -1)
        cout << "Not Found!!!" << endl;
    else
        cout << "Element found at index : " << x << endl;

    // using library

    int p = binary_search(a, a + n, key); // returns true element found
    cout << "Element Exist (in-built) ? : " << p;
    return 0;
}

/*

use " beg + (end - beg) / 2 " instead of " (beg + end)/2 "

*/