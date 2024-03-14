#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int pivotInteger5(int n)
    {
        // TC: O(n ^ 2)
        // SC: O(1)

        for (int pivot = 1; pivot <= n; pivot++)
        {
            int leftSum = 0;
            int rightSum = 0;

            for (int i = 1; i <= pivot; i++)
            {
                leftSum += i;
            }

            for (int i = pivot; i <= n; i++)
            {
                rightSum += i;
            }

            if (leftSum == rightSum)
                return pivot;
        }
        return -1;
    }

    // Better - using "Sum of n integers" formula
    int pivotInteger4(int n)
    {
        // TC: O(n)
        // SC: O(1)

        int totalSum = (n * (n + 1)) / 2;
        for (int pivot = 1; pivot <= n; pivot++)
        {
            int leftSum = (pivot * (pivot + 1)) / 2;
            int rightSum = totalSum - leftSum + pivot;

            if (leftSum == rightSum)
                return pivot;
        }
        return -1;
    }

    // Better - 2 pointer
    int pivotInteger3(int n)
    {
        // TC: O(n)
        // SC: O(1)

        int i = 1, j = n;
        int leftSum = 1, rightSum = n;
        while (i < j)
        {
            if (leftSum <= rightSum)
            {
                i++;
                leftSum += i;
            }
            else if (rightSum < leftSum)
            {
                j--;
                rightSum += j;
            }
        }
        if (leftSum == rightSum)
            return i;
        else
            return -1;
    }

    // Better - Binary Search
    int pivotInteger4(int n)
    {
        // TC: O(logn)
        // SC: O(1)

        int totalSum = (n * (n + 1)) / 2;
        int left = 1, right = n;
        while (left <= right)
        {
            int midPivot = left + (right - left) / 2;
            if (midPivot * midPivot == totalSum)
                return midPivot;
            else if (midPivot * midPivot < totalSum)
                left = midPivot + 1;
            else
                right = midPivot - 1;
        }
        return -1;
    }

    // Optimal - deriving formula
    int pivotInteger(int n)
    {
        // TC: O(n)
        // SC: O(1)

        int totalSum = (n * (n + 1)) / 2;
        int pivot = sqrt(totalSum);
        if (pivot * pivot == totalSum)
            return pivot;
        else
            return -1;
    }
};
int main()
{
    Solution s;
    int n = 8;
    cout << "Pivot Integer: " << s.pivotInteger(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-pivot-integer/

Youtube: https://www.youtube.com/watch?v=cPaq3AABkLc

algorithm:


- Optimal Approach:

- To find sum of numbers from 1 - x == x * (x + 1) / 2
- To find Total sum of n numbers == n * (n + 1) / 2
- To find sum of numbers from x - n == TotalSum - (x * (x + 1) / 2) + x.

- Lets assume x is the pivot element, then we can derive:

=> x * (x + 1) / 2 = TotalSum - (x * (x + 1) / 2) + x.
=> 2 * (x * (x + 1)) / 2 = TotalSum + x.
=> (x * (x + 1)) = TotalSum + x.
=> x^2 + x - x = TotalSum.
=> x^2 = TotalSum.
=> x = sqrt(TotalSum).

*/

/*

2485. Find the Pivot Integer

Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all
elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is
guaranteed that there will be at most one pivot index for the given input.

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.

Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.

*/