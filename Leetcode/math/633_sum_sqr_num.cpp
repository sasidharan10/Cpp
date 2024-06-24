#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force - Gives TLE
    bool judgeSquareSum3(int c)
    {
        // TC: O(m^2)  let m = sqrt(c)
        // SC: O(1)

        int m = sqrt(c);
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if ((i * i) + (j * j) == c)
                    return true;
            }
        }
        return false;
    }

    // Better - using set to find pairs which satisfy the condition
    bool judgeSquareSum2(int c)
    {
        // TC: O(m)  let m = sqrt(c)
        // SC: O(m)

        int m = sqrt(c);
        unordered_set<int> st;
        for (int i = 0; i <= m; i++)
        {
            st.insert(i * i);
        }

        for (int i = 0; i <= m; i++)
        {
            int b = c - i * i;
            if (st.find(b) != st.end())
                return true;
        }
        return false;
    }

    // Optimal - Using 2 pointers.
    bool judgeSquareSum(int c)
    {
        // TC: O(m)  let m = sqrt(c)
        // SC: O(1)

        int m = sqrt(c);
        long long i = 0, j = m;
        while (i <= j)
        {
            long long total = i * i + j * j;
            if (total == c)
                return true;
            else if (total < c)
                i++;
            else
                j--;
        }
        return false;
    }
};
int main()
{
    Solution s;
    // int c = 5;
    int c = 35;
    cout << "Result: " << s.judgeSquareSum(c) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sum-of-square-numbers/

Youtube: https://www.youtube.com/watch?v=B0UrG_X2faA

Code Link:

algorithm:

- Brute Force Approach:

- We know that we have to find the square of numbers, only till sqrt(c) = m.
- This is because, lets say x > sqrt(c). then x^2 will always be >>> c.
- Hence we only need to compute the numbers till m.
- Here we run to loops, to find all possible pairs, starting from 0 - m.
- T.C: O(m^2) gives TLE.

- Better

- We store all possible squares(lets say 'b') in a set from 0 - m.
- Then we loop from 0 - m, calculating 'a', and check if b is available
  in the set, if yes return true. b = c - a.

- Optimal Approach:

- We know that both numbers will be present in the range 0 - m.
- Hence we use a 2 pointer approach, where long i = 0, j = c;
- We calculate total = i * i + j * j, and check if its greater or less
  than c, and move the pointers correspondingly.

*/

/*

633. Sum of Square Numbers

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: c = 3
Output: false
 
Constraints:

0 <= c <= 231 - 1

*/

/*
************* Java Code **************

public boolean judgeSquareSum(int c) {
        int m = (int)Math.sqrt(c);
        long i = 0, j = m;
        while (i <= j)
        {
            long total = i * i + j * j;
            if (total == c)
                return true;
            else if (total < c)
                i++;
            else
                j--;
        }
        return false;
    }

*/