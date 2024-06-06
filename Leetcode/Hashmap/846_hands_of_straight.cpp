#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        // TC: O(nlogn) + O(n * groupSize)
        // SC: O(n)

        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[hand[i]]++;
        }
        while (!mp.empty())
        {
            int curr = mp.begin()->first;
            for (int i = 0; i < groupSize; i++)
            {
                // if (mp[curr + i] == 0)
                if (mp.find(curr + i) == mp.end())
                    return false;
                mp[curr + i]--;
                if (mp[curr + i] == 0)
                    mp.erase(curr + i);
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    // vector<int> nums{1, 2, 3, 4, 5};
    // int groupSize = 4;
    cout << "Result: " << s.isNStraightHand(nums, groupSize) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/hand-of-straights/

Youtube: https://www.youtube.com/watch?v=lpVhzcdiHMs

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashMap/Hand%20of%20Straights.cpp

algorithm:

- Optimal Approach:

- Using ordered map and removing "groupSize" elements from the map, which are
  consecutive.
- If they are not consecutive, return false.
- If map becomes empty, then all elements are consecutive, hence return true.

*/

/*

846. Hand of Straights

Alice has some number of cards and she wants to rearrange the cards into groups so 
that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an 
integer groupSize, return true if she can rearrange the cards, or false otherwise.

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length

*/

/*
************* Java Code **************

public boolean isNStraightHand(int[] hand, int groupSize) {
        int n = hand.length;
        if (n % groupSize != 0)
            return false;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(hand[i], mp.getOrDefault(hand[i], 0) + 1);
        }
        while (!mp.isEmpty()) {
            int curr = mp.firstKey();
            for (int i = 0; i < groupSize; i++) {
                if (!mp.containsKey(curr + i))
                    return false;
                mp.put(curr + i, mp.get(curr + i) - 1);
                if (mp.get(curr + i) == 0)
                    mp.remove(curr + i);
            }
        }
        return true;
    }

*/