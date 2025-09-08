#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long findMinOperations(priority_queue<int> &pq)
    {
        long long cnt = 0;
        // Keep reducing while more than 1 element exists and top is not zero
        while (pq.size() > 1 && pq.top() != 0)
        {
            int first = pq.top(); // largest element
            pq.pop();
            int second = pq.top(); // second largest element
            pq.pop();

            // Divide both by 4 (floor)
            int res1 = floor(first / 4);
            int res2 = floor(second / 4);

            // Push back only if results are non-zero
            if (res1 != 0)
                pq.push(res1);
            if (res2 != 0)
                pq.push(res2);

            cnt++; // one operation done
        }

        // If heap is empty, just return count
        if (pq.empty())
            return cnt;

        // Handle last remaining element
        int last = pq.top();
        cnt += (last > 0) ? 1 : 0;
        return cnt;
    }

    // Brute force - using heap
    long long minOperations2(vector<vector<int>> &queries)
    {
        // TC: O(nlogn) where n = end - start + 1
        // SC: O(n)

        int n = queries.size();
        long long mini = 0;

        for (int i = 0; i < n; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];

            priority_queue<int, vector<int>, less<int>> pq; // max-heap

            // Push all numbers from start to end into heap
            while (start <= end)
            {
                pq.push(start);
                start++;
            }

            // Process heap to find min operations
            mini += findMinOperations(pq);
        }
        return mini;
    }

    // Optimal - using intervals trick
    long long minOperations(vector<vector<int>> &queries)
    {
        // TC: O(O(n * log end))
        // SC: O(1)
        
        int n = queries.size();
        long long mini = 0;
        for (int i = 0; i < n; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];

            long long L = 1;     // left bound of current [L, R] block (powers of 4: 1,4,16,...)
            long long S = 1;     // step index (depth level) corresponding to current block
            long long steps = 0; // total weighted count within [start, end]

            // Iterate blocks as [L, R] where R = 4*L - 1, until L exceeds end
            while (L <= end)
            {
                long long R = L * 4 - 1; // right bound of current block

                // Overlap of current block with query range [start, end]
                long long newL = max(L, (long long)start);
                long long newR = min(R, (long long)end);

                // If there is overlap, add its contribution weighted by S
                if (newL <= newR)
                {
                    long long noOfElements = (newR - newL + 1) * S;
                    steps += noOfElements;
                }

                // Move to next block: increase depth S and jump L to next power-of-4 start
                S++;
                L = L * 4;
            }

            // Convert total steps to operation count (pairs rounded up)
            mini += (steps + 1) / 2;
        }
        return mini;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{1, 2}, {2, 4}};
    cout << "Result: " << s.minOperations(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/

Youtube: https://www.youtube.com/watch?v=VYDl3p9bkkw

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Intervals_Based_Qn/Minimum%20Operations%20to%20Make%20Array%20Elements%20Zero.cpp

algorithm:

- Brute Force Approach:

- Each query defines a range [start, end].
- All numbers in this range are inserted into a max-heap.
- At each step, the two largest numbers are removed, divided by 4, and pushed back if non-zero.
- Every such reduction counts as one operation.
- Process continues until the heap is empty or only one element remains.
- If one element remains, one more operation is added if it’s still non-zero.
- Final answer is the sum of operations across all queries.

- Optimal Approach:

- For each query [start, end], we look at numbers inside that range.
- Numbers are grouped into blocks of size that grow as powers of 4:
- first block = [1, 3], next = [4, 15], then [16, 63], and so on.
- Each block is given a “weight” (step number). First block weight = 1, second = 2, third = 3, etc.
- For the query range [start, end], we check how much of it falls inside each block.
- If some numbers overlap with the block, we add (count of those numbers × weight) to total steps.
- After finishing all blocks, total steps are turned into operations using (steps + 1) / 2.
- The sum of operations for all queries is returned.

*/

/*

3495. Minimum Operations to Make Array Elements Zero

You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array
of integers nums consisting of elements ranging from l to r, both inclusive.

In one operation, you can:

Select two integers a and b from the array.
Replace them with floor(a / 4) and floor(b / 4).
Your task is to determine the minimum number of operations required to reduce all elements of the array to
zero for each query. Return the sum of the results for all queries.

Example 1:

Input: queries = [[1,2],[2,4]]

Output: 3

Explanation:

For queries[0]:

The initial array is nums = [1, 2].
In the first operation, select nums[0] and nums[1]. The array becomes [0, 0].
The minimum number of operations required is 1.
For queries[1]:

The initial array is nums = [2, 3, 4].
In the first operation, select nums[0] and nums[2]. The array becomes [0, 3, 1].
In the second operation, select nums[1] and nums[2]. The array becomes [0, 0, 0].
The minimum number of operations required is 2.
The output is 1 + 2 = 3.

Example 2:

Input: queries = [[2,6]]

Output: 4

Explanation:

For queries[0]:

The initial array is nums = [2, 3, 4, 5, 6].
In the first operation, select nums[0] and nums[3]. The array becomes [0, 3, 4, 1, 6].
In the second operation, select nums[2] and nums[4]. The array becomes [0, 3, 1, 1, 1].
In the third operation, select nums[1] and nums[2]. The array becomes [0, 0, 0, 1, 1].
In the fourth operation, select nums[3] and nums[4]. The array becomes [0, 0, 0, 0, 0].
The minimum number of operations required is 4.
The output is 4.

Constraints:

1 <= queries.length <= 105
queries[i].length == 2
queries[i] == [l, r]
1 <= l < r <= 10^9

*/

/*
************* Java Code **************

    public long minOperations(int[][] queries) {
        int n = queries.length;
        long mini = 0;

        for (int i = 0; i < n; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            long L = 1;
            long S = 1;
            long steps = 0;

            while (L <= end) {
                long R = L * 4 - 1;
                long newL = Math.max(L, (long) start);
                long newR = Math.min(R, (long) end);

                if (newL <= newR) {
                    long noOfElements = (newR - newL + 1) * S;
                    steps += noOfElements;
                }

                S++;
                L = L * 4;
            }

            mini += (steps + 1) / 2;
        }

        return mini;
    }

*/