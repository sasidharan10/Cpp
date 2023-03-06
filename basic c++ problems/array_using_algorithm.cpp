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
    int *o;
    int *f = find(arr, arr + n, 15);
    // int *f = find(arr, arr + n, 38);
    // if (f == arr + n)
    //     cout << "Not found" << endl;
    // else
    //     cout << "found" << endl;
    int pos = (f - arr);
    cout << "\n(f - arr): " << (f - arr) << endl;
    // cout << "\n(f + arr): " << (f + arr) << endl;    // error: below
    cout << "Pos: " << pos << endl;
    cout << "Distance: " << distance(arr, find(arr, arr + n, 15)) << endl;
    cout << "Array: ";
    for (int i : arr)
        cout << i << " ";
    int c = count(arr, arr + n, 27);
    cout << "\nc: " << c << endl;
    cout << "Max: " << *max_element(arr, arr + n) << endl;
    cout << "Min: " << *min_element(arr, arr + n) << endl;
    sort(arr, arr + n);
    cout << "Sorted array: ";
    vector<int> v(10);
    int k = 0;
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = ++k;
    }
    for (int i : v)
        cout << i << " ";
    return 0;
}


/*

- When we abtract 2 pointers, it does not gives how many bytes they are apart
  but # of integers the pointers are apart. This is because the pointers are
  pointing to blocks of memory.
- We can subtract 2 pointers to find how much distance they are apart, but we 
  dont know where the new pointer will point to.


*/