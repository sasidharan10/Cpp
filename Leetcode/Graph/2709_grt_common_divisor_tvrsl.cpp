#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
    vector<int> parent, size;
    disjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        else if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution
{
public:
    // Brute force - gives TLE
    bool canTraverseAllPairs3(vector<int> &nums)
    {
        // TC: O(n^2 * log(max(a))) where a = element in nums
        // SC: O(n)

        int n = nums.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int gcd = __gcd(nums[i], nums[j]);
                if (gcd > 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, false);
        queue<int> que;
        que.push(0);
        vis[0] = true;
        while (!que.empty())
        {
            int node = que.front();
            que.pop();
            for (auto &&it : adj[node])
            {
                if (!vis[it])
                {
                    que.push(it);
                    vis[it] = true;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == false)
                return false;
        }
        return true;
    }

    // Better
    bool canTraverseAllPairs2(vector<int> &nums)
    {
        // TC: O(n * sqrt(m)) where m = max(nums[i])
        // SC: O(n + m)

        int n = nums.size();
        unordered_map<int, vector<int>> index2Prime;
        unordered_map<int, vector<int>> prime2Index;

        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];
            for (int factor = 2; factor * factor <= nums[i]; factor++)
            {
                if (temp % factor != 0)
                    continue;
                index2Prime[i].push_back(factor);
                prime2Index[factor].push_back(i);
                while (temp % factor == 0)
                {
                    temp /= factor;
                }
            }
            if (temp > 1)
            {
                index2Prime[i].push_back(temp);
                prime2Index[temp].push_back(i);
            }
        }

        vector<bool> indexVis(n, false);
        unordered_map<int, bool> primeVis;
        queue<int> que;
        que.push(0);
        indexVis[0] = true;
        while (!que.empty())
        {
            int index = que.front();
            que.pop();
            for (int prime : index2Prime[index])
            {
                if (primeVis[prime])
                    continue;
                primeVis[prime] = true;
                for (int childIndex : prime2Index[prime])
                {
                    if (indexVis[childIndex])
                        continue;
                    indexVis[childIndex] = true;
                    que.push(childIndex);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indexVis[i] == false)
                return false;
        }
        return true;
    }

    // Optimal - Using Disjoint Set
    bool canTraverseAllPairs(vector<int> &nums)
    {
        // TC: O(n * sqrt(m) * alpha) ,where m = max(nums[i])
        // SC: O(n)

        int n = nums.size();
        disjointSet ds(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];
            for (int factor = 2; factor * factor <= nums[i]; factor++)
            {
                if (temp % factor != 0)
                    continue;
                if (mp.find(factor) != mp.end())
                {
                    int idx = mp[factor];
                    ds.unionBySize(idx, i);
                }
                else
                    mp[factor] = i;

                while (temp % factor == 0)
                {
                    temp /= factor;
                }
            }
            if (temp > 1)
            {
                if (mp.find(temp) != mp.end())
                {
                    int idx = mp[temp];
                    ds.unionBySize(idx, i);
                }
                else
                    mp[temp] = i;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                cnt++;
            if (cnt > 1)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{4, 3, 12, 8};
    // vector<int> nums{3, 9, 5};
    vector<int> nums{2, 3, 6};
    cout << "Result: " << s.canTraverseAllPairs(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/greatest-common-divisor-traversal

Youtube:

algorithm:

- If n == 1, then return true.
- If the array contains 1, which means, it will have gcd() == 1 with
  all other elements and hence we cannot take that element. hence, we can
  return false, without computing further.

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

2709. Greatest Common Divisor Traversal

You are given a 0-indexed integer array nums, and you are allowed to traverse
between its indices. You can traverse between index i and index j, i != j, if
and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.

Your task is to determine if for every pair of indices i and j in nums,
where i < j, there exists a sequence of traversals that can take us from i to j.

Return true if it is possible to traverse between all such pairs of indices, or false otherwise.

Example 1:

Input: nums = [2,3,6]
Output: true
Explanation: In this example, there are 3 possible pairs of indices: (0, 1), (0, 2), and (1, 2).
To go from index 0 to index 1, we can use the sequence of traversals 0 -> 2 -> 1,
where we move from index 0 to index 2 because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1,
and then move from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1.
To go from index 0 to index 2, we can just go directly because
gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1. Likewise, to go from index 1 to index 2,
we can just go directly because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1.

Example 2:

Input: nums = [3,9,5]
Output: false
Explanation: No sequence of traversals can take us from index 0 to index 2
in this example. So, we return false.

Example 3:

Input: nums = [4,3,12,8]
Output: true
Explanation: There are 6 possible pairs of indices to traverse between:
(0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of
traversals exists for each pair, so we return true.

*/

/*

public static boolean canTraverseAllPairs(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return true;
        HashMap<Integer, ArrayList<Integer>> index2Prime = new HashMap<>();
        HashMap<Integer, ArrayList<Integer>> prime2Index = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            if (temp == 1)
                return false;
            for (int factor = 2; factor * factor <= nums[i]; factor++) {
                if (temp % factor != 0)
                    continue;
                if (!index2Prime.containsKey(i))
                    index2Prime.put(i, new ArrayList<>());
                index2Prime.get(i).add(factor);

                if (!prime2Index.containsKey(factor))
                    prime2Index.put(factor, new ArrayList<>());
                prime2Index.get(factor).add(i);

                while (temp % factor == 0) {
                    temp /= factor;
                }
            }
            if (temp > 1) {
                if (!index2Prime.containsKey(i))
                    index2Prime.put(i, new ArrayList<>());
                index2Prime.get(i).add(temp);

                if (!prime2Index.containsKey(temp))
                    prime2Index.put(temp, new ArrayList<>());
                prime2Index.get(temp).add(i);
            }
        }
        boolean[] indexVis = new boolean[n];
        Arrays.fill(indexVis, false);
        HashMap<Integer, Boolean> primeVis = new HashMap<>();
        Queue<Integer> que = new LinkedList<>();
        que.offer(0);
        indexVis[0] = true;
        while (!que.isEmpty()) {
            int index = que.poll();
            for (int prime : index2Prime.get(index)) {
                if (primeVis.getOrDefault(prime, false))
                    continue;
                primeVis.put(prime, true);
                for (int childIndex : prime2Index.get(prime)) {
                    if (indexVis[childIndex] == true)
                        continue;
                    indexVis[childIndex] = true;
                    que.offer(childIndex);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (indexVis[i] == false)
                return false;
        }
        return true;
    }

    // using Disjoint Set
    public static boolean canTraverseAllPairs(int[] nums) {
        int n = nums.length;
        disjointSet ds = new disjointSet(n);
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            for (int factor = 2; factor * factor <= nums[i]; factor++) {
                if (temp % factor != 0)
                    continue;
                if (mp.containsKey(factor)) {
                    int idx = mp.get(factor);
                    ds.unionBySize(idx, i);
                } else
                    mp.put(factor, i);

                while (temp % factor == 0) {
                    temp /= factor;
                }
            }
            if (temp > 1) {
                if (mp.containsKey(temp)) {
                    int idx = mp.get(temp);
                    ds.unionBySize(idx, i);
                } else {
                    mp.put(temp, i);
                }
            }
        }
        return ds.getNoOfComponents() == 1;
    }

*/