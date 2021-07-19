#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
    pair<int, int> p1(10, 20);
    // 10,20
    pair<char, int> p2;
    p2.first = 'a';
    p2.second = 30;
    cout << p2.first << " : ";
    cout << p2.second << endl;
    vector<pair<int, string>> v;
    v.push_back(make_pair(1, "kane"));
    v.push_back(make_pair(2, "root"));
    v.push_back(pair<int,string>(3, "smith"));
    v.push_back(pair<int,string>(4, "kohli"));
    cout << "Pairs are : " << endl;
    for (auto i : v)
    {
        cout << i.first << " : " << i.second << endl;
    }
    return 0;
}