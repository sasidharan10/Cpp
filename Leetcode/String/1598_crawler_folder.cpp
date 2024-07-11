#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - Using stack
    int minOperations(vector<string> &logs)
    {
        // TC: O(n)
        // SC: O(n)

        int n = logs.size();
        stack<string> st;
        for (int i = 0; i < n; i++)
        {
            if (logs[i] == "./")
                continue;
            else if (logs[i] == "../")
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(logs[i]);
            }
        }
        return st.size();
    }

    // Optimal
    int minOperations2(vector<string> &logs)
    {
        // TC: O(n)
        // SC: O(1)

        int n = logs.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (logs[i] == "./")
                continue;
            else if (logs[i] == "../")
            {
                if (cnt > 0)
                    cnt--;
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<string> nums{"d1/", "d2/", "../", "d21/", "./"};
    cout << "Result: " << s.minOperations(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/crawler-log-folder

Youtube: https://www.youtube.com/watch?v=xAI0hcwzuuE

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Stack/Easy/Crawler%20Log%20Folder.cpp

algorithm:

- Optimal Approach:

- just keep track of depth of folder.

*/

/*

1598. Crawler Log Folder

The Leetcode file system keeps a log each time some user performs a change folder operation.

The operations are described below:

"../" : Move to the parent folder of the current folder. (If you are already in the main folder,
remain in the same folder).
"./" : Remain in the same folder.
"x/" : Move to the child folder named x (This folder is guaranteed to always exist).
You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

The file system starts in the main folder, then the operations in logs are performed.

Return the minimum number of operations needed to go back to the main folder after the change
folder operations.

Example 1:

Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.

Example 2:

Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3

Example 3:

Input: logs = ["d1/","../","../","../"]
Output: 0

Constraints:

1 <= logs.length <= 10^3
2 <= logs[i].length <= 10
logs[i] contains lowercase English letters, digits, '.', and '/'.
logs[i] follows the format described in the statement.
Folder names consist of lowercase English letters and digits.

*/

/*
************* Java Code **************

public static int minOperations(String[] logs) {
        int n = logs.length;
        int depth = 0;
        for (int i = 0; i < n; i++) {
            if (logs[i].equals("./"))
                continue;
            else if (logs[i].equals("../")) {
                if (depth > 0)
                    depth--;
            } else {
                depth++;
            }
        }
        return depth;
    }

*/