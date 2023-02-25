#include <iostream>
using namespace std;
int main()
{
    int *p;
    int arr[]{1, 2, 3, 4, 5, 6, 7};
    p = arr;
    cout << "sizeof(arr): " << sizeof(arr) << endl;   // compiler knows its an array, hence returns total size
    cout << "sizeof(&arr): " << sizeof(&arr) << endl; // size of pointer
    cout << "sizeof(arr[0]): " << sizeof(arr[0]) << endl;
    cout << "sizeof(p): " << sizeof(p) << endl;
    return 0;
}