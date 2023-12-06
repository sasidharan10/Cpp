#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int totalMoney2(int n)
    {
        // TC: O(n)
        // SC: O(1)
        
        int ans = 0, start = 1, days = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (days < 7)
            {
                ans += cnt;
                cnt++;
                days++;
            }
            else
            {
                start++;
                cnt = start;
                ans += cnt;
                cnt++;
                days = 1;
            }
        }
        return ans;
    }
    // Better
    int totalMoney(int n)
    {
        // TC: O(1)
        // SC: O(1)

        int weeks = n / 7;
        int remaining_days = n % 7;
        int first = 28;                            // sum of first 7 days
        int last = 28 + (weeks - 1) * 7;           // using AP formula to find last term
        int result = (weeks) * (first + last) / 2; // Using AP to find sum of n terms
        int start_value = weeks + 1;               // start value of last week will be = week count + 1.
        for (int days = 0; days < remaining_days; days++)
        {
            result += start_value;
            start_value++;
        }
        return result;
    }
};
int main()
{
    Solution s;
    int n = 10;
    cout << "Result: " << s.totalMoney(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/calculate-money-in-leetcode-bank

Youtube: https://www.youtube.com/watch?v=TAmv6Csq3Ss

algorithm:

- Arithmetic progression
- Find a(n)th term = a + (n-1)*d;
- Sum of n terms, S(n) = {  (n/2) * (a + a(n))  } OR {  (n/2) * (2a + (n-1)*d)  }
*/

/*

1716. Calculate Money in Leetcode Bank

Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, 
he will put in $1 more than the day before. On every subsequent Monday, he will put in 
$1 more than the previous Monday.
Given n, return the total amount of money he will have in the Leetcode bank at the 
end of the nth day.

Example 1:

Input: n = 4
Output: 10
Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
Example 2:

Input: n = 10
Output: 37
Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7)
 + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.
Example 3:

Input: n = 20
Output: 96
Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7)
 + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.


*/