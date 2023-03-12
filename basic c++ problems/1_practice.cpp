#include <iostream>
#include <string>
using namespace std;
void reverse_string(int n, char *a)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(a[i++], a[j--]);
    }
}
int main()
{
    char arr[] = "creative";
    cout << "String: ";
    for (auto i : arr)
    {
        cout << i;
    }
    cout << endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse_string(n, arr);
    cout << "Reversed string: ";
    for (auto i : arr)
    {
        cout << i;
    }

    return 0;
}