#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int maximum69Number3(int num)
    {
        // TC: O(n^2)
        // SC: O(n)

        int maxi = num;
        string str = to_string(num); // O(n)
        int sz = str.length();
        for (int i = 0; i < sz; i++)
        {
            string temp = str; // O(n) copy
            temp[i] = '9';
            int tempNum = stoi(temp); // O(n) conversion
            maxi = max(maxi, tempNum);
        }
        return maxi;
    }

    // Better
    int maximum69Number2(int num)
    {
        // TC: O(n)
        // SC: O(n)

        string str = to_string(num); // O(n)
        for (char &c : str)          // O(n)
        {
            if (c == '6')
            {
                c = '9';
                break; // flip only the first '6'
            }
        }
        return stoi(str); // O(n)
    }

    // Optimal
    int maximum69Number(int num)
    {
        // TC: O(n)
        // SC: O(1)

        int pos = -1;
        int idx = 0;

        int temp = num;
        while (temp > 0)
        {
            int remainder = temp % 10;

            if (remainder == 6)
                pos = idx;

            temp /= 10;
            idx++;
        }

        if (pos == -1)
            return num;

        return num + 3 * pow(10, pos);
    }
};
int main()
{
    Solution s;
    int num = 9669;
    cout << "Result: " << s.maximum69Number(num) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-69-number

Youtube: https://www.youtube.com/watch?v=6dh1H5Hv4TI

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Greedy/Maximum%2069%20Number.cpp

algorithm:

- Brute Force Approach:

- Convert number to string.
- For each digit: flip it to '9', convert back, take max.
- Time: O(d²) (string copy + stoi inside loop).

- Better:

- Convert number to string.
- Flip the first '6' to '9'.
- Convert back to int.
- Time: O(d).

- Optimal Approach:

- Scan digits from right to left.
- Track the most significant '6'.
- Add 3 * 10^pos to number.
- Time: O(d) → practically O(1) (since d ≤ 5).

*/

/*

1323. Maximum 69 Number

You are given a positive integer num consisting only of digits 6 and 9.
Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.

Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.

Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.

Constraints:

1 <= num <= 10^4
num consists of only 6 and 9 digits.

*/

/*
************* Java Code **************

    public int maximum69Number(int num) {
        int pos = -1;
        int idx = 0;

        int temp = num;
        while (temp > 0) {
            int remainder = temp % 10;

            if (remainder == 6)
                pos = idx;

            temp /= 10;
            idx++;
        }

        if (pos == -1)
            return num;

        return num + 3 * (int)(Math.pow(10, pos));
    }

*/