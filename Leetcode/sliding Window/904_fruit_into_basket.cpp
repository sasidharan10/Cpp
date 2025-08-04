#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - but not intuitive (storing last seen index of leftmost fruit).
    int totalFruit3(vector<int> &fruits)
    {
        // TC: O(n * m) - each fruit is visited at most twice
        // SC: O(n) - in worst case, map stores all different fruits temporarily

        int n = fruits.size();
        unordered_map<int, int> mp; // Stores fruit type and its latest index
        int maxi = 0;
        int i = 0, j = 0; // Window boundaries

        while (j < n)
        {
            mp[fruits[j]] = j; // Update the last seen index of current fruit
            if (mp.size() > 2)
            {
                // More than 2 types of fruits → need to shrink the window
                int minIndex = INT_MAX;
                int fruitToRemove = -1;

                // Find the fruit with the earliest last seen index (leftmost fruit)
                for (auto &p : mp)
                {
                    if (p.second < minIndex)
                    {
                        minIndex = p.second;
                        fruitToRemove = p.first;
                    }
                }
                // Remove that fruit from map and move left pointer just after it
                i = minIndex + 1;
                mp.erase(fruitToRemove);
            }
            // Update max window size
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }

    // better - storing frequency of fruits in map, and shrinking, if size exceeds 2.
    int totalFruit2(vector<int> &fruits)
    {
        // TC: O(n) – each element is visited at most twice
        // SC: O(n) – stores at most 2 fruit types at any time

        int n = fruits.size();
        unordered_map<int, int> mp; // Fruit type → count in current window
        int maxi = 0;
        int i = 0, j = 0; // Sliding window pointers

        while (j < n)
        {
            mp[fruits[j]]++; // Add current fruit to basket

            // Shrink window if more than 2 fruit types
            while (mp.size() > 2)
            {
                mp[fruits[i]]--; // Remove fruit at left
                if (mp[fruits[i]] == 0)
                    mp.erase(fruits[i]); // Remove type if count becomes 0
                i++;                     // Move left pointer
            }

            // Update max window length
            maxi = max(maxi, j - i + 1);
            j++; // Expand right pointer
        }
        return maxi;
    }

    // Optimal - Similar to previous approach, but we just shrink the window by 1 index.
    int totalFruit(vector<int> &fruits)
    {
        // TC: O(n) – each element is visited at most twice
        // SC: O(n) – at most 2 fruit types are stored in the map

        int n = fruits.size();
        unordered_map<int, int> mp; // Fruit type → count in current window
        int maxi = 0;
        int i = 0, j = 0; // Window pointers

        while (j < n)
        {
            mp[fruits[j]]++; // Include current fruit in the window

            // If window has more than 2 types, shrink from left
            if (mp.size() > 2)
            {
                mp[fruits[i]]--; // Remove one count of leftmost fruit
                if (mp[fruits[i]] == 0)
                    mp.erase(fruits[i]); // Remove type if count becomes 0
                i++;                     // Move left pointer forward
            }

            // Update max window length
            maxi = max(maxi, j - i + 1);
            j++; // Expand window from right
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{1, 2, 3, 2, 2};
    vector<int> nums{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Result: " << s.totalFruit(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/fruit-into-baskets/

Youtube: https://www.youtube.com/watch?v=QBi5_btsse4

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Fruit%20Into%20Baskets.cpp

algorithm:

- Optimal Approach:

- Goal: Find the longest subarray with at most 2 distinct fruit types.
- Use two pointers (i, j) to form a dynamic sliding window.
- Use a hashmap to count frequency of fruits in the current window.
- Expand j while adding fruits to the map.
- Use if (mp.size() > 2) instead of while:
    - Because only one fruit type can cause the size to exceed 2.
    - We find the leftmost fruit (smallest index), remove it, and move i just once.
    - No need for repeated shrinking like in while, as the condition will be fixed in one step.
- After fixing the window, update maxi with the current window size.
- Return the maximum found.

*/

/*

904. Fruit Into Baskets

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are 
represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on 
the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the 
start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


*/

/*
************* Java Code **************

    public int totalFruit(int[] fruits) {
        // TC: O(n)
        // SC: O(n)

        int n = fruits.length;
        Map<Integer, Integer> mp = new HashMap<>();
        int maxi = 0;
        int i = 0, j = 0;

        while (j < n) {
            mp.put(fruits[j], mp.getOrDefault(fruits[j], 0) + 1);

            if (mp.size() > 2) {
                mp.put(fruits[i], mp.get(fruits[i]) - 1);
                if (mp.get(fruits[i]) == 0) {
                    mp.remove(fruits[i]);
                }
                i++;
            }

            maxi = Math.max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }

*/