#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    // vector<string> str = {"a", "b", "d", "c", "f", "e"};
    vector<string> str = {"a", "b", "c", "d", "e"};
    int n = str.size();
    int r = 7;
    string st = "a";
    string end = "e";
    int st_index = 0;
    int end_index = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == st)
        {
            st_index = i;
        }
        if (str[i] == end)
        {
            end_index = i;
        }
    }
    // cout << st_index << endl;
    // int new_n = (n / 2) + (n % 2);
    int new_n = (n / 2);
    int move = r % new_n;
    int forward = (st_index + (2 * (move))) % n;
    int backward = (st_index - (2 * move) + n) % n;
    // cout << move << "" << endl;
    // cout << forward << "" << endl;
    // cout << str[forward] << "" << endl;
    // cout << str[backward] << "" << endl;
    int direction = 0;
    int next_index = 0;
    if (str[forward] == end)
    {
        direction = 0;
        next_index = (end_index + (2 * (1))) % n;
        cout << "Clockwise: " << endl;
    }
    else
    {
        direction = 1;
        next_index = (end_index - (2 * 1) + n) % n;
        cout << "Anti-Clockwise: " << endl;
    }
    cout << "Current: " << st << endl;
    cout << "next index: " << str[next_index] << endl;
    cin >> n;
    return 0;
}