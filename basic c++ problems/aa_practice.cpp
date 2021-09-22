#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int main()
{

    int a[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n, greater<int>());
    for (int i : a)
        cout << i << " ";
    return 0;
}