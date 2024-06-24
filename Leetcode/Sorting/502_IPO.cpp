#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // T.C: O(nlogn) + O(n)
        // S.C: O(n)

        int n = profits.size();
        vector<pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp.push_back({capital[i], profits[i]});
        }

        sort(mp.begin(), mp.end());
        priority_queue<int, vector<int>, less<int>> pq;
        int idx = 0;
        
        while (k > 0)
        {
            while (idx < n && mp[idx].first <= w)
            {
                int pft = mp[idx].second;
                pq.push(pft);
                idx++;
            }
            if (pq.empty())   // means no project aquired, hence we return w.
                break;
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};
int main()
{
    Solution s;
    // vector<int> profits = {1, 2, 3}, capital = {0, 1, 2};
    // int k = 3, w = 0;
    vector<int> profits = {1, 2, 3}, capital = {1, 1, 2};
    int k = 1, w = 2;
    cout << "Result: " << s.findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/ipo/

Youtube: https://www.youtube.com/watch?v=b12SZXrZF9I

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Heap/IPO.cpp

algorithm:

- Optimal Approach:

- make list of pairs, with first element as the capital, and second as profit.
- Sort the list based on capital.
- Now iterate through the list, and check if we can take the current pair.
- i.e., (w >= current capital), means we can aquire that project, hence 
  push that profit to a max-heap.
- Since there will be 'm' projects which we can aquire, but we will pick the
  project with "max" profit. hence we add pq.top() in the result and pop it.
- We do this until (k==0), since we can only aquire 'k' projects.
- If (w < current capital), then we cannot aquire any further projects, hence
  we break the loop and return w.

*/

/*

502. IPO

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares
to Venture Capital, LeetCode would like to work on some projects to increase its capital
before the IPO. Since it has limited resources, it can only finish at most k distinct
projects before the IPO. Help LeetCode design the best way to maximize its total
capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a
minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure
profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final
capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2
to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.

Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6

Constraints:

1 <= k <= 105
0 <= w <= 109
n == profits.length
n == capital.length
1 <= n <= 105
0 <= profits[i] <= 104
0 <= capital[i] <= 109

*/

/*
************* Java Code **************

public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        List<int[]> mp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            mp.add(new int[] { capital[i], profits[i] });
        }

        Comparator cmp = new Comparator<int[]>() {

            public int compare(int[] arr1, int[] arr2) {
                return Integer.compare(arr1[0], arr2[0]);
            }
        };

        Collections.sort(mp, cmp);
        for (int[] is : mp) {
            for (int is2 : is) {
                System.out.print(is2 + ", ");
            }
            System.out.println();
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        int idx = 0;

        while (k > 0) {
            while (idx < n && mp.get(idx)[0] <= w) {
                int pft = mp.get(idx)[1];
                pq.add(pft);
                idx++;
            }
            if (pq.isEmpty())
                break;
            w += pq.poll();
            k--;
        }
        return w;
    }

*/