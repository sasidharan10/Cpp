#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums{2, 4, 6, 1, 4, 8};
    for (int it : nums)
    {
        cout << it * 2 << ", ";
    }
    cout << endl;
    for (int it : nums)
    {
        cout << it<< ", ";
    }
    return 0;
}