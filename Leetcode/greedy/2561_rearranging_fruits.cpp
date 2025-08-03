#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        // TC: O(nlogn) due to sorting
        // SC: O(n) for storing imbalance elements

        int n = basket1.size();
        unordered_map<int, int> mp; // To track net frequency difference between baskets
        int mini = INT_MAX;         // To track the smallest element in both baskets

        // Step 1: Build frequency difference map and find the minimum element
        for (int i = 0; i < n; i++)
        {
            mp[basket1[i]]++;                           // Increment count for basket1 element
            mp[basket2[i]]--;                           // Decrement count for basket2 element
            mini = min({mini, basket1[i], basket2[i]}); // Update minimum element
        }

        vector<int> swapElements; // Store excess elements to be swapped

        // Step 2: Collect unbalanced elements (those whose freq diff != 0)
        for (auto it : mp)
        {
            int num = it.first;
            int freq = it.second;

            if (freq % 2 != 0)
                return -1; // Cannot balance if frequency is odd

            // Push half the excess frequency (each swap fixes 2 units of imbalance)
            for (int i = 0; i < abs(freq) / 2; i++)
            {
                swapElements.push_back(num);
            }
        }

        // Step 3: Sort the elements to prioritize cheaper swaps
        sort(swapElements.begin(), swapElements.end());

        int sz = swapElements.size();
        long long minCost = 0;

        // Step 4: For the first half of swapElements, calculate the cost
        // Either directly swap (cost = value), or do double swap with smallest element (cost = 2 * mini)
        for (int i = 0; i < sz / 2; i++)
        {
            minCost += min(mini * 2, swapElements[i]);
        }

        return minCost; // Return the total minimum cost
    }
};
int main()
{
    Solution s;
    vector<int> basket1 = {4, 2, 2, 2}, basket2 = {1, 4, 1, 2};
    cout << "Result: " << s.minCost(basket1, basket2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/rearranging-fruits/

Youtube: https://www.youtube.com/watch?v=xveEovkFjBU

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Greedy/Rearranging%20Fruits.cpp

algorithm:

- Optimal Approach:

- Use a hashmap to count the difference in frequency of each element between the two baskets.
- If any element has an odd difference, return -1 (cannot make both baskets identical).
- Track the minimum element in both baskets to consider for cheaper double swaps.
- For each element with imbalance, add half of its count to a list (each swap fixes 2 elements).
- Sort this list to prioritize cheaper swaps.
- For the first half of the list, add to cost the minimum of:
    → the element itself, or
    → twice the smallest element in all baskets (double swap trick).
- Return the total cost.

*/

/*

2561. Rearranging Fruits

You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1
and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so,
you can use the following operation as many times as you want:

Choose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
The cost of the swap is min(basket1[i], basket2[j]).
Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.

Example 1:

Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and
basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.

Example 2:

Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
Output: -1
Explanation: It can be shown that it is impossible to make both the baskets equal.

Constraints:

basket1.length == basket2.length
1 <= basket1.length <= 10^5
1 <= basket1[i], basket2[i] <= 10^9

*/

/*
************* Java Code **************

    public long minCost(int[] basket1, int[] basket2) {
        // TC: O(nlogn) due to sorting
        // SC: O(n) for storing imbalance elements

        int n = basket1.length;
        Map<Integer, Integer> mp = new HashMap<>(); // To track net frequency difference
        int mini = Integer.MAX_VALUE;               // To track the smallest element

        for (int i = 0; i < n; i++) {
            mp.put(basket1[i], mp.getOrDefault(basket1[i], 0) + 1); // Increment for basket1
            mp.put(basket2[i], mp.getOrDefault(basket2[i], 0) - 1);  // Decrement for basket2
            mini = Math.min(mini, Math.min(basket1[i], basket2[i])); // Update minimum
        }

        List<Integer> swapElements = new ArrayList<>();

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int num = entry.getKey();
            int freq = entry.getValue();

            if (freq % 2 != 0)
                return -1;

            for (int i = 0; i < Math.abs(freq) / 2; i++) {
                swapElements.add(num);
            }
        }

        Collections.sort(swapElements);

        int sz = swapElements.size();

        long minCost = 0;
        for (int i = 0; i < sz / 2; i++) {
            minCost += Math.min(mini * 2, swapElements.get(i));
        }

        return minCost;
    }

*/