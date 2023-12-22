#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2];

    bool containKey(int num)
    {
        return links[num] != nullptr;
    }

    Node *get(int num)
    {
        return links[num];
    }

    void put(int num, Node *node)
    {
        links[num] = node;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            // 1 - bit == (compliment of bit) or use "!bit"
            if (node->containKey(1 - bit))
            {
                res = res | (1 << i);
                node = node->get(1 - bit);
            }
            else
                node = node->get(bit);
        }
        return res;
    }
};

class Solution
{
public:
    // Brute force
    vector<int> maxXorQueries2(vector<int> &nums, vector<vector<int>> &queries)
    {
        // TC: O(n*m)
        // SC: O(m) - storing answer

        int n = nums.size();
        int m = queries.size();
        int maxi = 0;
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int xi = queries[i][0];
            int ai = queries[i][1];
            maxi = -1;
            for (int j = 0; j < n; j++)
            {
                int temp;
                if (nums[j] <= ai)
                {
                    temp = xi ^ nums[j];
                    maxi = max(maxi, temp);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }

    // Optimal
    vector<int> maxXorQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        // TC: O(nlogn) + O(m) + O(m + n)
        // SC: undefined

        Trie t;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> qr;
        int m = queries.size();
        for (int i = 0; i < m; i++)
        {
            int xi = queries[i][0];
            int ai = queries[i][1];
            qr.push_back({ai, {xi, i}});
        }
        sort(qr.begin(), qr.end());
        vector<int> ans(m, 0);
        int curIndex = 0;
        int maxi = 0;
        for (int i = 0; i < m; i++)
        {
            int ai = qr[i].first;
            int xi = qr[i].second.first;
            int qIndex = qr[i].second.second;

            while (curIndex < n && nums[curIndex] <= ai)
            {
                t.insert(nums[curIndex]);
                curIndex++;
            }
            if (curIndex == 0)
            {
                ans[qIndex] = -1;
                continue;
            }
            maxi = t.getMax(xi);
            ans[qIndex] = maxi;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{6, 6, 3, 5, 2, 4};
    vector<vector<int>> queries{{6, 3}, {8, 1}, {12, 4}};
    vector<int> ans = s.maxXorQueries(nums, queries);
    cout << "Maximum XOR With an Element From Array: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/max-xor-queries_1382020

leetcode: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

Youtube: https://www.youtube.com/watch?v=Q8LhG9Pi5KM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=7

algorithm:

- Optimal approach

- We use trie DS to store the numbers, so we can do the XOR operation efficiently.
- But as per the problem, we cannot add all numbers into the trie, as it is stated
  that, only arr[i] <= ai values can be used to perform this operation.
- So a naive approach will be create the trie for every m queries, and then
  do the XOR operation, which will take O(n*32*m) TC. Not efficient.
- Better approach: use "offline queries". In this method, we sort the
  queries based on the limit provided in the query(ai).
- So, as the query limit(ai) increases, we just have to add more values
  into the same trie, hence, reduces time complexity.
- 1 catch here is, we also have to note the queries indices also, since
  we have to return the answer, in the order of the query.
- We also sort the array, so that, we can just traverse those elements
  whole values are arr[i] <= ai, hence, no need to traverse whole array.
- if there is no element with arr[i] <= ai, then we assign -1 as answer.

*/

/*

1707. Maximum XOR With an Element From Array

You are given an array nums consisting of non-negative integers. You are 
also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and 
any element of nums that does not exceed mi. In other words, the answer 
is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements 
in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and 
answer[i] is the answer to the ith query.

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 
and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.

Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]

*/