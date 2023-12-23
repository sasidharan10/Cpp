#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPathCrossing(string path)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = path.length();
        unordered_set<string> st;
        int row = 0, col = 0;
        st.insert(to_string(row) + '_' + to_string(col));
        for (int i = 0; i < n; i++)
        {
            if (path[i] == 'N')
                row++;
            else if (path[i] == 'S')
                row--;
            else if (path[i] == 'E')
                col++;
            else if (path[i] == 'W')
                col--;
            string str = to_string(row) + '_' + to_string(col);
            if (i != 0 && st.find(str) != st.end())
                return true;
            st.insert(str);
        }
        return false;
    }
};
int main()
{
    Solution s;
    string path = "NESWW";
    // string path = "NES";
    // string path = "NNSWWEWSSESSWENNW";
    cout << "Is Path Crossing: " << s.isPathCrossing(path) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/path-crossing

Youtube:

algorithm:

- keep track of points, using 2 variables, and store it in a set.
- as we traverse the path, check if we already stored the point,
  if yes, return true.
- convert the coordinates into string, since it will take less space
  compared to storing as pairs, and we can use unordered_set to store strings.

*/

/*

1496. Path Crossing

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing 
moving one unit north, south, east, or west, respectively. You start at the 
origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time 
you are on a location you have previously visited. Return false otherwise.

Example 1:

Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.

Example 2:

Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.

*/