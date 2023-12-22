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
    // Optimal
    int findMaximumXOR(vector<int> &nums)
    {
        // TC: O(n*32)
        // SC: Cannot specify

        Trie t;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            t.insert(nums[i]);
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = t.getMax(nums[i]);
            maxi = max(maxi, temp);
        }
        return maxi;
    }

    // Brute Force - gives TLE
    int findMaximumXOR2(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    int temp = nums[i] ^ nums[j];
                    maxi = max(maxi, temp);
                }
            }
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    int n = 7, m = 7;
    vector<int> nums{3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR of Two Numbers in an Array: " << s.findMaximumXOR(nums) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/maximum-xor_973113

leetcode: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

Youtube: https://www.youtube.com/watch?v=EIhAwfHubE8&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=6

algorithm:

- Here, we store every number of arr1 in trie, as 32 bit representation.
  then we take each element from arr2 and iterate it with the trie.
- To get max XOR, the leftmost bit should give 1 as answer, if we do the XOR operation.
- lets say num's current bit is "bit". Now to get 1 as result, that trie should have
  a reference to !bit (a ^ b == 1, if a and b are different). if yes, then we move to
  that trie, and eliminating other path, as they cant have max value,
  since this is the leftmost bit.
- if !bit is not present, then we can move to next trie and check again.

*/

/*

421. Maximum XOR of Two Numbers in an Array

Given an integer array nums, return the maximum result of
nums[i] XOR nums[j], where 0 <= i <= j < n.

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

*/