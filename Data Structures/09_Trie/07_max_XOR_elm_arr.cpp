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
    vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        // TC: O(n*m)
        // SC: O(m) - storing answer

        int n = arr.size();
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
                if (arr[j] <= ai)
                {
                    temp = xi ^ arr[j];
                    maxi = max(maxi, temp);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }

    // Optimal
    vector<int> maxXorQueries2(vector<int> &arr, vector<vector<int>> &queries)
    {
        // TC: O(nlogn) + O(m) + O(m + n)
        // SC: undefined

        Trie t;
        int n = arr.size();
        sort(arr.begin(), arr.end());

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

            while (curIndex < n && arr[curIndex] <= ai)
            {
                t.insert(arr[curIndex]);
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

Maximum XOR With an Element From Array

You are given an array/list ‘ARR’ consisting of ‘N’ non-negative integers.
You are also given a list ‘QUERIES’ consisting of ‘M’ queries, where
the ‘i-th’ query is a list/array of two non-negative
integers ‘Xi’, ‘Ai’, i.e ‘QUERIES[i]’ = [‘Xi’, ‘Ai’].

The answer to the ith query, i.e ‘QUERIES[i]’ is the maximum bitwise
xor value of ‘Xi’ with any integer less than or equal to ‘Ai’ in ‘ARR’.

You should return an array/list consisting of ‘N’ integers where
the ‘i-th’ integer is the answer of ‘QUERIES[i]’.

Sample Input 1:
2
5 2
0 1 2 3 4
1 3
5 6
1 1
1
1 0

Sample Output 1:
3 7
-1

Explanation of sample input 1:
In the first test case, the answer of query [1, 3] is 3 because 1^2 = 3 and 2 <= 3,
and the answer of query [5, 6] is 7 because  5 ^ 2 = 7 and 2 <= 6.

In the second test case, no element is less than or equal to 0 in the given array ‘ARR’.

*/