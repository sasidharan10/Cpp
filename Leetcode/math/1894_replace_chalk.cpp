#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - simulation
    int chalkReplacer2(vector<int> &chalk, int k)
    {
        // TC: O(m) let k/sum = m. but m can reach upto 10^9, hence it gives TLE.
        // SC: O(1)

        int n = chalk.size();
        int idx = 0;
        while (k >= chalk[idx])
        {
            k -= chalk[idx];
            idx++;
            idx %= n;
        }
        return idx;
    }

    // Optimal - math
    int chalkReplacer(vector<int> &chalk, int k)
    {
        // TC: O(n) + O(n)
        // SC: O(1)

        int n = chalk.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += chalk[i];
            /*
            - optimization: if sum > k, then we only need 1 iteration to find the index, hence 
              we break the loop here itself, and no need to take the sum of array.
            - since sum > k, k % sum will be equal to k. (no changes)
            */
            if (sum > k)
                break;
        }
        int remaining = (long long)k % sum;
        for (int i = 0; i < n; i++)
        {
            if (chalk[i] <= remaining)
                remaining -= chalk[i];
            else
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> chalk{3, 4, 1, 2};
    int k = 25;
    cout << "Result: " << s.chalkReplacer2(chalk, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

Youtube: https://www.youtube.com/watch?v=RG-vw6IzVuU

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Find%20the%20Student%20that%20Will%20Replace%20the%20Chalk.cpp

algorithm:

- Brute Force Approach:

- Iterate through the array and keep subtracting chalk[i] from k.
- If array ends, again start from 0.
- Repeat the process until k < chalk[i]. Then return i.

- Optimal Approach:

- lets say chalk = [3,4,1,2], k = 105
- Sum of array = 10.
- In 1 iteration, k becomes 95, then 85, then 75 and so on.
- So if k > sum, then we can subtract the sum without iterating through the array, as
  we know, index "i" will again come to index 0.
- Hence we take the mod, to eliminate these iterations.
- Now k < sum, so we can iterate through the array, and find the index,
  where k < chalk[i].

*/

/*

1894. Find the Student that Will Replace the Chalk

There are n students in a class numbered from 0 to n - 1. The teacher will give each student a
problem starting with the student number 0, then the student number 1, and so on until the
teacher reaches the student number n - 1. After that, the teacher will restart the process,
starting with the student number 0 again.

You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of
chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of
chalk to solve that problem. However, if the current number of chalk pieces is strictly less than
chalk[i], then the student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk pieces.

Example 1:

Input: chalk = [5,1,5], k = 22
Output: 0
Explanation: The students go in turns as follows:
- Student number 0 uses 5 chalk, so k = 17.
- Student number 1 uses 1 chalk, so k = 16.
- Student number 2 uses 5 chalk, so k = 11.
- Student number 0 uses 5 chalk, so k = 6.
- Student number 1 uses 1 chalk, so k = 5.
- Student number 2 uses 5 chalk, so k = 0.
Student number 0 does not have enough chalk, so they will have to replace it.

Example 2:

Input: chalk = [3,4,1,2], k = 25
Output: 1
Explanation: The students go in turns as follows:
- Student number 0 uses 3 chalk so k = 22.
- Student number 1 uses 4 chalk so k = 18.
- Student number 2 uses 1 chalk so k = 17.
- Student number 3 uses 2 chalk so k = 15.
- Student number 0 uses 3 chalk so k = 12.
- Student number 1 uses 4 chalk so k = 8.
- Student number 2 uses 1 chalk so k = 7.
- Student number 3 uses 2 chalk so k = 5.
- Student number 0 uses 3 chalk so k = 2.
Student number 1 does not have enough chalk, so they will have to replace it.

Constraints:

chalk.length == n
1 <= n <= 10^5
1 <= chalk[i] <= 10^5
1 <= k <= 10^9

*/

/*
************* Java Code **************

    public static int chalkReplacer(int[] chalk, int k) {
        int n = chalk.length;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += chalk[i];
        }
        long remaining = (long) k % sum;
        for (int i = 0; i < n; i++) {
            if (chalk[i] <= remaining)
                remaining -= chalk[i];
            else
                return i;
        }
        return -1;
    }

*/