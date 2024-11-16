#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    int maximumSwap2(int num)
    {
        // TC: O(n^2)
        // SC: O(1)
        
        string str = to_string(num);
        int n = str.length();
        bool foundMax = false;
        for (int i = 0; i < n - 1; i++)
        {
            int curmaxIdx = i;
            int curMaxElement = str[i];
            // traversing from reverse, to store the rightmost max element index.
            for (int j = n - 1; j >= i + 1; j--)
            {
                if (str[j] > curMaxElement)
                {
                    curmaxIdx = j;
                    curMaxElement = str[j];
                    foundMax = true;
                }
            }
            if (foundMax)
            {
                swap(str[i], str[curmaxIdx]);
                return stoi(str);
            }
        }
        return num;
    }
    // optimal - using max array.
    int maximumSwap(int num)
    {
        // TC: O(n)
        // SC: O(n)

        string str = to_string(num);
        int n = str.length();
        vector<int> maxRight(n, 0);
        maxRight[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int maxRightIdx = maxRight[i + 1];
            int maxRightElement = str[maxRightIdx];
            maxRight[i] = (str[i] > maxRightElement) ? i : maxRightIdx;
        }

        for (int i = 0; i < n; i++)
        {
            int maxRightIdx = maxRight[i];
            int maxRightElement = str[maxRightIdx];
            if (str[i] < maxRightElement)
            {
                swap(str[i], str[maxRightIdx]);
                return stoi(str);
            }
        }
        return num;
    }
};
int main()
{
    Solution s;
    // int num = 2736;
    int num = 1993;
    cout << "Result: " << s.maximumSwap2(num) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-swap

Youtube: https://www.youtube.com/watch?v=6tsqLTvLAf8

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Maximum%20Swap.cpp

algorithm:

- Brute Force Approach:

- Finding the max element to the right side from each index.
- If found, then we swap it and return the result.

- Optimal Approach:

- Instead of traversing everytime, to find max element present in right side
  of any givrn element, we those results in an array called maxRight, to access them in O(1) T.C.
- Now the complexity is reduced to O(n), but S.C is O(n).

*/

/*

670. Maximum Swap

You are given an integer num. You can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.

Constraints:

0 <= num <= 10^8

*/

/*
************* Java Code **************

    public static int maximumSwap(int num) {
        String str = Integer.toString(num);
        char[] strArray = str.toCharArray();
        int n = strArray.length;
        int[] maxRight = new int[n];
        maxRight[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            int maxRightIdx = maxRight[i + 1];
            int maxRightElement = strArray[maxRightIdx];
            maxRight[i] = (strArray[i] > maxRightElement) ? i : maxRightIdx;
        }

        for (int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i];
            int maxRightElement = strArray[maxRightIdx];
            if (strArray[i] < maxRightElement) {
                char temp = strArray[i];
                strArray[i] = strArray[maxRightIdx];
                strArray[maxRightIdx] = temp;
                return Integer.parseInt(new String(strArray));
            }
        }
        return num;
    }

*/