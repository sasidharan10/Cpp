#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Using elements as index
    vector<string> findRelativeRanks3(vector<int> &score)
    {
        // TC: O(n) + O(maxi)
        // SC: O(maxi)

        int n = score.size();
        int maxi = *max_element(score.begin(), score.end());
        vector<int> mp(maxi + 1, -1);
        for (int i = 0; i < n; i++)
        {
            mp[score[i]] = i;
        }
        int rank = 1;
        vector<string> ans(n);
        for (int i = maxi; i >= 0; i--)
        {
            if (mp[i] == -1)
                continue;
            int idx = mp[i];
            if (rank == 1)
                ans[idx] = "Gold Medal";
            else if (rank == 2)
                ans[idx] = "Silver Medal";
            else if (rank == 3)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(rank);
            rank++;
        }
        return ans;
    }

    // using heap
    vector<string> findRelativeRanks2(vector<int> &score)
    {
        // TC: O(nlogn)
        // SC: O(n)

        int n = score.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({score[i], i});
        }
        int rank = 1;
        vector<string> ans(n);
        while (!pq.empty())
        {
            int scr = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (rank == 1)
                ans[idx] = "Gold Medal";
            else if (rank == 2)
                ans[idx] = "Silver Medal";
            else if (rank == 3)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(rank);
            rank++;
        }
        return ans;
    }

    // Using sorting
    vector<string> findRelativeRanks(vector<int> &score)
    {
        // TC: O(nlogn)
        // SC: O(1) ~ without ans array
        
        int n = score.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[score[i]] = i;
        }
        sort(score.begin(), score.end(), greater<>());
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            int idx = mp[score[i]];
            if (i == 0)
                ans[idx] = "Gold Medal";
            else if (i == 1)
                ans[idx] = "Silver Medal";
            else if (i == 2)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(i + 1);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{10, 3, 8, 9, 4};
    vector<string> ans = s.findRelativeRanks(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/relative-ranks/

Youtube: https://www.youtube.com/watch?v=0UFVdlS2nwI

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Relative%20Ranks.cpp

algorithm:

- Optimal Approach:

- Self explanatory

*/

/*

506. Relative Ranks

You are given an integer array score of size n, where score[i] is the score of the
ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the
highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement
of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e.,
the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

*/

/*
************* Java Code **************

public static String[] findRelativeRanks(int[] score) {
        int n = score.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]); // map heap
        for (int i = 0; i < n; i++) {
            pq.add(new int[] { score[i], i });
        }
        int rank = 1;
        String[] ans = new String[n];
        while (!pq.isEmpty()) {
            int scr = pq.peek()[0];
            int idx = pq.peek()[1];
            pq.poll();
            if (rank == 1)
                ans[idx] = "Gold Medal";
            else if (rank == 2)
                ans[idx] = "Silver Medal";
            else if (rank == 3)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = Integer.toString(rank);
            rank++;
        }
        return ans;
    }

*/