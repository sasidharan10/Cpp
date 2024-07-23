#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal - Using map to sort the names based on heights
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        // TC: O(nlogn)
        // SC: O(n)
        
        int n = names.size();
        map<int, string, greater<>> mp;
        for (int i = 0; i < n; i++)
        {
            mp.insert({heights[i], names[i]});
        }
        int i = 0;
        for (auto &&it : mp)
        {
            names[i] = it.second;
            i++;
        }
        return names;
    }
};
int main()
{
    Solution s;
    vector<string> names = {"Mary", "John", "Emma"};
    vector<int> heights = {180, 165, 170};
    vector<string> ans = s.sortPeople(names, heights);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sort-the-people

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Use a map and sort based on heights.
- Traverse through the map and store the names in an array and return it.

*/

/*

2418. Sort the People

You are given an array of strings names, and an array heights that consists of distinct 
positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 
Constraints:

n == names.length == heights.length
1 <= n <= 10^3
1 <= names[i].length <= 20
1 <= heights[i] <= 10^5
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.


*/

/*
************* Java Code **************

public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        Map<Integer, String> mp = new TreeMap<>(Comparator.reverseOrder());
        for (int i = 0; i < n; i++)
        {
            mp.put(heights[i], names[i]);
        }
        int i = 0;
        for (String it : mp.values())
        {
            names[i] = it;
            i++;
        }
        return names;
    }

*/