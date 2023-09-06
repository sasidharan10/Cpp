#include <iostream>
#include <string>
#include <vector>
#include <cstring> // string.h in c+ (header file for memset)
using namespace std;
int main()
{
    int arr[10];
    cout << sizeof(arr) << endl;
    memset(arr, -1, sizeof(arr)); // works only for 0,-1 integers(since memset works byte by byte).
    cout << "Array  : ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    string str = "abcdefghijk"; // good for initialising strings and char array
    cout << "String : " << str << endl;
    vector<int> v{1, 2, 3, 4, 5};
    cout << "sizeof(v): " << sizeof(v) << endl;
    cout << "sizeof(v[0]): " << sizeof(v[0]) << endl;
    cout << "sizeof(str): " << sizeof(str) << endl;
    cout << "sizeof(str[0]): " << sizeof(str[0]) << endl;
    memset(&str[0] + 3, '@', 5 * sizeof(str[0]));
    cout << str;
    return 0;
}