#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> v1{{1, 3}, {6, 4}, {3, 2}, {2, 8}};
    sort(v1.begin(), v1.end()); // sorts based on row elements
    cout << "2D vector : " << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[0].size(); j++)
        {
            cout << v1[i][j] << " ";
        }
        cout << endl;
    }
    // we can have any number of elements in a row of vector
    vector<vector<int>> v2{
        {1, 2},
        {4, 5, 6},
        {7, 8, 9, 10}};
    cout << "2D vector (using forEach) : " << endl;
    for (vector<int> vec : v2)
    {
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    int r = 2;
    int c = 3;
    cout << "Vector initialising with 0 : " << endl;
    vector<vector<int>> v3(r, vector<int>(c, 0));
    for (vector<int> vec : v3)
    {
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    vector<int> v4 = v1[0];
    cout << "Initialising a row of 2D vector to a 1D vector" << endl;
    for (int i : v4)
    {
        cout << i << " ";
    }
    return 0;
}