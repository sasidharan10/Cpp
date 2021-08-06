#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
void print(array<int, 5> a)
{
    cout << "List : ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    vector<int> v;
    array<int, 5> arr = {1, 2, 3, 4, 5};
    int a[5] = {1, 2, 3, 4, 5};
    print(arr);
    return 0;
}