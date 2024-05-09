#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force - Gives TLE
    long long maximumHappinessSum3(vector<int> &happiness, int k)
    {
        // TC: O(n * k)
        // SC: O(1)

        int n = happiness.size();
        int decr = 0;
        int maxi = 0;
        int maxIndex = 0;
        long long res = 0;
        int t = 0;
        while (t < k)
        {
            if (t == 0)
                decr = 0;
            else
                decr = 1;
            for (int i = 0; i < n; i++)
            {
                if (happiness[i] == 0)
                    continue;
                else if (happiness[i] - decr >= 0)
                    happiness[i] = happiness[i] - decr;
                else
                    happiness[i] = 0;
                if (happiness[i] > maxi)
                {
                    maxi = happiness[i];
                    maxIndex = i;
                }
            }
            res += maxi;
            happiness[maxIndex] = 0;
            maxi = 0;
            t++;
        }
        return res;
    }

    // Using heap
    long long maximumHappinessSum2(vector<int> &happiness, int k)
    {
        // TC: O(nlogn) O(k)
        // SC: O(n)
        
        int n = happiness.size();
        int decr = 0;
        long long res = 0;
        priority_queue<int, vector<int>, less<>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(happiness[i]);
        }
        while (k--)
        {
            int num = pq.top();
            pq.pop();
            if (num - decr >= 0)
                res = res + num - decr;
            decr++;
        }
        return res;
    }

    // Sorting
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        // TC: O(nlogn) + O(k)
        // SC: O(1)

        int n = happiness.size();
        int decr = 0;
        long long res = 0;
        sort(happiness.begin(), happiness.end());
        int i = n - 1;
        while (k--)
        {
            if (happiness[i] - decr >= 0)
                res = res + happiness[i] - decr;
            decr++;
            i--;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 3, 4, 5};
    int k = 3;
    cout << "Result: " << s.maximumHappinessSum(nums, k) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

Code Link:

algorithm:

- Its similar to finding sum of max k elements in an array. Only differnce is,
  We have to decrease the value of next element by "Decr".
- decr increase after every k elements are added to the list.

- Brute Force Approach:

- traverse k times in the array, and decrement the value by everytime.
- If value goes below 0, make it 0.
- Find the max in each traversal, and add it to the res.
- In first traversal, we dont decrement the value in arr.

- Optimal Approach:

- using heap or sort the array.
- get the max value from the array and decrement it by "derc" times.
- "decr" increases in each k traversals.

*/

/*

3075. Maximize Happiness of Selected Children

You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value
happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children
that have not been selected till now decreases by 1. Note that the happiness
value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can
achieve by selecting k children.

Example 1:

Input: happiness = [1,2,3], k = 2
Output: 4
Explanation: We can pick 2 children in the following way:
- Pick the child with the happiness value == 3. The happiness value of the
remaining children becomes [0,1].
- Pick the child with the happiness value == 1. The happiness value of the
remaining child becomes [0]. Note that the happiness value cannot become less than 0.
The sum of the happiness values of the selected children is 3 + 1 = 4.

Example 2:

Input: happiness = [1,1,1,1], k = 2
Output: 1
Explanation: We can pick 2 children in the following way:
- Pick any child with the happiness value == 1. The happiness value of the
  remaining children becomes [0,0,0].
- Pick the child with the happiness value == 0. The happiness value of the
  remaining child becomes [0,0].
The sum of the happiness values of the selected children is 1 + 0 = 1.

Example 3:

Input: happiness = [2,3,4,5], k = 1
Output: 5
Explanation: We can pick 1 child in the following way:
- Pick the child with the happiness value == 5. The happiness value of the
  remaining children becomes [1,2,3].
The sum of the happiness values of the selected children is 5.

*/

/*
************* Java Code **************

public long maximumHappinessSum(int[] happiness, int k) {
        int n = happiness.length;
        int decr = 0;
        long res = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i = 0; i < n; i++) {
            pq.add(happiness[i]);
        }
        while (k > 0) {
            int num = pq.poll();
            if (num - decr >= 0)
                res = res + num - decr;
            decr++;
            k--;
        }
        return res;
    }

*/