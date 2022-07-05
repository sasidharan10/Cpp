#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v({1, 2, 3, 4, 5, 6});
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
    }
    cout << "Running Sum: ";
    for (auto i : v)
        cout<< i << " ";
    return 0;
}