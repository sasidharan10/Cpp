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
            // 1 - bit == (compliment of bit)
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
    int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
    {
        // TC: O(n*32) + O(m*32)
        // SC: Cannot specify
        
        Trie t;
        for (int i = 0; i < n; i++)
        {
            t.insert(arr1[i]);
        }
        int maxi = 0;
        for (int i = 0; i < m; i++)
        {
            int temp = t.getMax(arr2[i]);
            maxi = max(maxi, temp);
        }
        return maxi;
    }
    // Brute Force
    int maxXOR2(int n, int m, vector<int> &arr1, vector<int> &arr2)
    {
        // TC: O(n^2)
        // SC: O(1)
        
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp = arr1[i] ^ arr2[j];
                maxi = max(maxi, temp);
            }
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    int n = 7, m = 7;
    vector<int> nums1{6, 6, 0, 6, 8, 5, 6};
    vector<int> nums2{1, 7, 1, 7, 8, 0, 2};
    cout << "Result: " << s.maxXOR2(n, m, nums1, nums2) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/maximum-xor_973113

leetcode:

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

Maximum XOR

You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’.
Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’
are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’
represents the bitwise xor operation.

Sample Input 1:
1
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2

Sample Output 1:
15

Explanation of sample input 1:
First testcase:
Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2).
And 8 xor 7 will give the maximum result i.e. 15

*/