#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Helper function to convert a number to a string, sort its digits, and return the sorted string
    string getSortedStr(int n)
    {
        string str = to_string(n);
        sort(str.begin(), str.end());
        return str;
    }

    // Solution 4: Compare sorted digit strings of n and all power-of-2 numbers
    bool reorderedPowerOf2_4(int n)
    {
        // TC: O(n) - where n is the number of digits in n and power-of-2 numbers
        // SC: O(n) - for storing and sorting strings

        string str = getSortedStr(n); // Get sorted digit string of input n

        // Check against all possible power-of-2 numbers (2^0 to 2^29)
        for (int p = 0; p <= 29; p++)
        {
            if (str == getSortedStr(1 << p)) // Compare sorted digit strings
                return true;
        }
        return false;
    }

    // Solution 3: Precompute all power-of-2 digit strings and use a set for lookup
    bool reorderedPowerOf2_3(int n)
    {
        // TC: O(dlogd) - where d is the number of digits (sorting each power-of-2)
        // SC: O(d) - for storing digit strings in a set

        // Build a set of all sorted digit strings for power-of-2 numbers
        unordered_set<string> st;

        for (int p = 0; p <= 29; p++)
        {
            int num = 1 << p;               // Calculate 2^p
            string temp = to_string(num);   // Convert to string
            sort(temp.begin(), temp.end()); // Sort digits
            st.insert(temp);                // Store in set
        }

        // Get sorted digit string of input n and check if it exists in the set
        string str = to_string(n);
        sort(str.begin(), str.end());

        return st.count(str); // Returns true if found in set
    }

    // Helper function to get digit frequency count as a vector
    vector<int> getVectorCountFormat(int n)
    {
        vector<int> vec(10, 0); // Initialize vector to count digits 0-9

        // Count each digit in the number
        while (n)
        {
            vec[n % 10]++; // Increment count for current digit
            n /= 10;       // Remove last digit
        }
        return vec;
    }

    // Solution 2: Compare digit frequency vectors of n and all power-of-2 numbers
    bool reorderedPowerOf2_2(int n)
    {
        // TC: O(d) - where d is the number of digits (no sorting needed)
        // SC: O(1) - fixed size vectors (10 elements each)

        vector<int> input = getVectorCountFormat(n); // Get digit counts for input

        // Compare against all power-of-2 numbers' digit counts
        for (int p = 0; p <= 29; p++)
        {
            if (input == getVectorCountFormat(1 << p)) // Direct vector comparison
            {
                return true;
            }
        }
        return false;
    }

    // Helper function to create a unique number representing digit frequencies
    int getNumberCountFormat(int n)
    {
        int num = 0;

        // Create a number where each digit's place represents a count
        // e.g., digit '2' appears 3 times -> adds 100 to the number (10^2 + 10^2 + 10^2)
        while (n)
        {
            num += pow(10, n % 10); // Add 10^digit to the number
            n /= 10;                // Remove last digit
        }

        return num;
    }

    // Solution 1: Compare digit frequency numbers of n and all power-of-2 numbers
    bool reorderedPowerOf2(int n)
    {
        // TC: O(d) - where d is the number of digits
        // SC: O(1) - constant space

        int input = getNumberCountFormat(n); // Get digit frequency number for input

        // Compare against all power-of-2 numbers' digit frequency numbers
        for (int p = 0; p <= 29; p++)
        {
            if (input == getNumberCountFormat(1 << p))
            {
                return true;
            }
        }

        return false;
    }
};
int main()
{
    Solution s;
    int n = 2480;
    cout << "Result: " << s.reorderedPowerOf2_4(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reordered-power-of-2

Youtube: https://www.youtube.com/watch?v=_Y8xqGvZu8M

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Mathematical/Reordered%20Power%20of%202.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

You are given an integer n. We reorder the digits in any order (including the original order) such that
the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Example 1:

Input: n = 1
Output: true

Example 2:

Input: n = 10
Output: false

Constraints:

1 <= n <= 10^9

*/

/*
************* Java Code **************

    private int getCountNumber(int n) {
        int num = 0;
        while (n > 0) {
            num += Math.pow(10, n % 10);
            n /= 10;
        }
        return num;
    }

    public boolean reorderedPowerOf2(int n) {
        int inputCount = getCountNumber(n);

        for (int p = 0; p <= 29; p++) {
            if (inputCount == getCountNumber(1 << p)) {
                return true;
            }
        }

        return false;
    }

*/