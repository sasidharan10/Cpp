#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void addOne(string &s)
    {
        int n = s.length();
        int i = n - 1;
        while (i >= 0 && s[i] == '1')
        {
            s[i] = '0';
            i--;
        }
        if (i < 0)
            s = '1' + s;
        else
            s[i] = '1';
    }
    // Brute force
    int numSteps2(string s)
    {
        // TC: O(n^2)
        // SC: O(1)
        
        int n = s.length();
        int ops = 0;
        while (s.length() > 1)
        {
            if (s[s.length() - 1] == '0')
                s.pop_back();
            else
                addOne(s);
            ops++;
        }
        return ops;
    }

    // Optimal
    int numSteps(string s)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = s.length();
        int ops = 0;
        int carry = 0;

        for (int i = n - 1; i >= 1; i--)
        {
            if (((s[i] - '0') + carry) % 2 == 1)
            {
                ops += 2;
                carry = 1;
            }
            else
                ops += 1;
        }
        return ops + carry;
    }
};
int main()
{
    Solution s;
    string str = "1101";
    cout << "Result: " << s.numSteps(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

Youtube: https://www.youtube.com/watch?v=sGweAOKMyeI&t=1s

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Number%20of%20Steps%20to%20Reduce%20a%20Number%20in%20Binary%20Representation%20to%20One.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

1404. Number of Steps to Reduce a Number in Binary Representation to One

Given the binary representation of an integer as a string s, return the number of steps to
reduce it to 1 under the following rules:
If the current number is even, you have to divide it by 2.
If the current number is odd, you have to add 1 to it.
It is guaranteed that you can always reach one for all test cases.

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14.
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.
Step 5) 4 is even, divide by 2 and obtain 2.
Step 6) 2 is even, divide by 2 and obtain 1.

Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.

Example 3:

Input: s = "1"
Output: 0

*/

/*
************* Java Code **************



*/