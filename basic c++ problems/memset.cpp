#include <iostream>
#include <string>
#include <cstring> // string.h in c+ (header file for memset)
using namespace std;
int main()
{
    int arr[10];
    memset(arr, 0, sizeof(arr)); // works only for 0,-1(since memset works byte by byte).
    cout << "Array  : ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "String : ";
    string str = "abcdefghijk"; // good for initialising strings and char array
    memset(&str[0] + 3, '@', 5 * sizeof(str[0]));
    cout << str;
    return 0;
}