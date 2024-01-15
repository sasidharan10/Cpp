#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPlaceBalls(int m, int diff, int n, vector<int> &position)
    {
        int cowCount = 1;
        int lastPlaced = position[0];
        for (int i = 1; i < n; i++)
        {
            if (position[i] - lastPlaced >= diff)
            {
                lastPlaced = position[i];
                cowCount++;
            }
            if (cowCount >= m)
                return true;
        }
        return false;
    }
    // Brute
    int maxDistance2(vector<int> &position, int m)
    {
        // TC: O(maxi - mini)*n or similar to  O(n^2)
        // SC: O(1)

        int n = position.size();
        sort(position.begin(), position.end());
        int mini = 1, maxi = position[n - 1] - position[0];
        int i = mini;
        for (i = mini; i <= maxi; i++)
        {
            if (canPlaceBalls(m, i, n, position))
                continue;
            else
                return (i - 1);
        }
        return i - 1;
    }

    // Optimal
    int maxDistance(vector<int> &position, int m)
    {
        // TC: O(maxi - mini) * logn
        // SC: O(1)

        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1, high = position[n - 1] - position[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canPlaceBalls(m, mid, n, position))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 7};
    int m = 4;
    // vector<int> nums{1, 2, 3};
    // int k = 2;
    cout << "Result: " << s.maxDistance(nums, m) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/aggressive-cows_1082559

leetcode: https://leetcode.com/problems/magnetic-force-between-two-balls/

gfg: https://www.geeksforgeeks.org/problems/aggressive-cows/0

Youtube: https://www.youtube.com/watch?v=R_Mfw4ew-Vo&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=18&t=1s

algorithm:

- We sort the array, since the positions can be interchangable in the given.
- The min difference possible between 2 balls can be 1 and max difference will be
  position[n - 1] - position[0].
- We check for every difference from i = 1 to maxi, and see if we can place m balls with
  "i" diff. If no, then the ans = i - 1;
- For optimal approach, we use binary search instead of linear search.
- We are trying for max number in the binary search (right to left), hence the answer
  will end at "high".

*/

/*

You are given an array consisting of n integers which denote the position of a stall.
You are also given an integer k which denotes the number of aggressive cows.
You are given the task of assigning stalls to k cows such that the minimum
distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5
k=3
stalls = [1 2 4 8 9]

Output:
3

Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[2] and
the third cow can be placed at stalls[3].
The minimum distance between cows, in this case, is 3,
which also is the largest among all possible ways.
Example 2:

Input:
n=5
k=3
stalls = [10 1 2 7 5]

Output:
4

Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4,
which also is the largest among all possible ways.

Your Task:
Complete the function int solve(), which takes integer n, k, and a vector stalls
with n integers as input and returns the largest possible minimum distance between cows.

*/