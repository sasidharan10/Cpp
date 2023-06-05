#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1{1, 2, 3};
    vector<int> v2{1, 2, 3};
    vector<int> v3{1, 2, 3};
    map<int, vector<int>> m;
    m.insert({1, v1});
    m.insert({2, v2});
    m.insert({3, v3});
    for (auto &&i : m)
    {
        cout << i.first << " : ";
        for (auto &&k : i.second)
        {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}