#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        // TC: O(n)
        // SC: O(n)

        if (n == 1)
            return {0};
        int temp = 1;
        vector<int> ans;
        if (n % 2 != 0)
            ans.push_back(0);
        for (int i = 0; i < n / 2; i++)
        {
            ans.push_back(temp);
            ans.push_back(-temp);
            temp++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    // int n = 5;
    int n = 6;
    vector<int> ans = s.sumZero(n);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

Youtube:

algorithm:

Code Link:

- Optimal Approach:

-

*/

/*

1304. Find N Unique Integers Sum up to Zero

Given an integer n, return any array containing n unique integers such that they add up to 0.

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Example 2:

Input: n = 3
Output: [-1,0,1]

Example 3:

Input: n = 1
Output: [0]

*/

/*   
************* Java Code **************

public static int[] sumZero(int n) {
        // TC: O(n)
        // SC: O(n)

        int[] ans = new int[n];
        int idx = 0;
        if (n % 2 != 0) {
            ans[0] = 0;
            idx = 1;
        }
        int temp = 1;
        for (int i = 0; i < n / 2; i++) {
            ans[idx++] = temp;
            ans[idx++] = -temp;
            temp++;
        }
        return ans;
    }

*/