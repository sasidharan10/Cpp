#include <bits/stdc++.h>
using namespace std;
void rotateLeft(vector<int>::iterator i, vector<int>::iterator j)
{
    while (i < j)
    {
        swap(*i, *j);
        j--;
    }
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    rotateLeft(arr.begin(), arr.end() - 1);
    cout << "Result: " << endl;
    for (auto &&i : arr)
    {
        cout << i << " ";
    }
    return 0;
}