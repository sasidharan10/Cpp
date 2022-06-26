#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int arr[]{20, 24, 12, 15, 27, 11, 18, 15, 21, 26, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array: ";
    for (int i : arr)
        cout << i << " ";
    int *f = find(arr, arr + n, 15);
    // int *f = find(arr, arr + n, 38);
    // if (f == arr + n)
    //     cout << "Not found" << endl;
    // else
    //     cout << "found" << endl;
    int pos = (f - arr) / (arr + 1 - arr);
    cout << "\n(f - arr): " << (f - arr) << endl;
    cout << "(arr + 1 - arr): " << (arr + 1 - arr) << endl;
    cout << "\nPos: " << pos << endl;
    for (int i : arr)
        cout << i << " ";
    int c = count(arr, arr + n, 27);
    cout << "\nc: " << c << endl;
    sort(arr, arr + n);
    cout << "\nSorted array: ";
    cout << "\nMax: " << *max_element(arr, arr + n) << endl;
    cout << "Min: " << *min_element(arr, arr + n) << endl;
    vector<int> v(10);
    int k = 0;
    for (int i = 0; i < v.size(); i++)
    {
        v[i]=++k;
    }
    cout << endl;
    for (int i : v)
        cout << i << " ";
    return 0;
}