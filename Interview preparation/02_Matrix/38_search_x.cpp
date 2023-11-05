#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void search1(vector<vector<int>> v, int x)
{
    // Time : O(n*m)
    // Space : O(1)

    if (v.size() == 0)
        cout << "Not Found!!!" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == x)
            {
                cout << "Element Found at : (" << i << ", " << j << ")" << endl;
                return;
            }
        }
    }
    cout << "Not Found!!!" << endl;
}
void search2(vector<vector<int>> v, int x)
{
    // Time : O(n+m)
    // Space : O(1)

    int n = v.size();
    int m = v[0].size();
    int i = 0;     // start of row
    int j = m - 1; // end of column in that same row (top-right corner)

    // checking if array is empty

    if (n == 0)
    {
        cout << "Not Found!!!" << endl;
        return;
    }

    // Edge cases to eliminate elements not in the array range O(1)

    int smallest = v[0][0];
    int largest = v[n - 1][m - 1];
    if (x < smallest || x > largest)
    {
        cout << "Not Found!!!" << endl;
        return;
    }

    while (i < n && j >= 0)
    {
        if (v[i][j] == x)
        {
            cout << "Element Found at : (" << i << ", " << j << ")" << endl;
            return;
        }
        else if (v[i][j] > x)
            j--;
        else
            i++;
    }
    cout << "Not Found!!!" << endl;
}
void search3(vector<vector<int>> v, int x)
{
    // Time : O(log(n*m))
    // Space : O(1)

    int n = v.size();
    int m = v[0].size();
    int low = 0;
    int high = (n * m) - 1;
    if (n == 0)
        cout << "Not Found!!!" << endl;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (v[mid / m][mid % m] == x)
        {
            cout << "Element Found at : (" << mid / m << ", " << mid % m << ")" << endl;
            return;
        }
        else if (x > v[mid / m][mid % m])
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Not Found!!!" << endl;
}
int main()
{
    vector<vector<int>> mat = {{10, 20, 30, 40},
                               {15, 25, 35, 45},
                               {27, 29, 37, 48},
                               {32, 33, 39, 50}};
    search1(mat, 32);
    search2(mat, 32);
    search3(mat, 32);
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/search-a-2d-matrix/description/

Youtube: 

algorithm: 

- In third solution, we do binary search in the matrix by making imaginary
  index of a 1D array. To get the row, we use mid/m (mid/column) formula 
  for columns we use mid%m (mid/Column) formula.
 
*/