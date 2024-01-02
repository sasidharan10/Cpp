#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // TC: O(nlogn) + O(mlogm)
        // SC: O(n)

        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, cnt = 0;
        while (i < n && j < m)
        {
            if (g[i] <= s[j])
            {
                cnt++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> g = {1, 2}, nums = {1, 2, 3};
    cout << "MAx count of children who got the cookies: ";
    cout << s.findContentChildren(g, nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/assign-cookies

Youtube: https://www.youtube.com/watch?v=oyzF9AsOUQ8

algorithm:

- 'g' denotes the no of students and g[i] denotes that student's greed factor.
- 's' denotes the size of cookies.
- If(g[i] <= s[j]), means s[j] cookies satisfies the greed of g[i] student
  hence he can eat that cookie.
- Our goal is to maximize the count of children, who ate the cookies.
- Hence to maximize the count, we sort both the arrays, so that, the child
  with least greed factor, can consume the cookie with minimum size.
- Ex: g = [1,2,4,7], s = [8,3,4,1]
- Here, without sorting, if we assign the cookies, the count will be 3.
- Ex: g = [1,2,4,7], s = [1,3,4,8]
- After sorting, cnt = 4.

*/

/*

455. Assign Cookies

Assume you are an awesome parent and want to give your children some
cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a
cookie that the child will be content with; and each cookie j has a
size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i,
and the child i will be content. Your goal is to maximize the number
of your content children and output the maximum number.

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors
of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1,
you could only make the child whose greed factor is 1 content.
You need to output 1.

Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
You need to output 2.

*/