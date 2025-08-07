#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // Brute force
  bool hasDuplicate(vector<int> &nums)
  {
    // TC: O(n^2)
    // SC: O(1)

    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        if (nums[i] == nums[j])
        {
          return true;
        }
      }
    }
    return false;
  }

  // Better - sorting
  bool hasDuplicate(vector<int> &nums)
  {
    // TC: O(nlogn)
    // SC: O(1)

    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] == nums[i - 1])
      {
        return true;
      }
    }
    return false;
  }

  // using set
  bool hasDuplicate(vector<int> &nums)
  {
    // TC: O(n)
    // SC: O(n)

    unordered_set<int> seen;
    for (int num : nums)
    {
      if (seen.count(num))
      {
        return true;
      }
      seen.insert(num);
    }
    return false;
  }

  // using map and finding freq count
  bool containsDuplicate(vector<int> &nums)
  {
    // TC: O(n)
    // SC: O(n)

    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      if (mp[nums[i]] > 0)
        return true;
      else
        mp[nums[i]]++;
    }
    return false;
  }
};
int main()
{
  Solution s;
  // vector<int> nums{1, 2, 3, 1};
  vector<int> nums{1, 2, 3, 4};
  cout << "Contains Duplicate?: " << s.containsDuplicate(nums) << endl;
  return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/contains-duplicate/

Youtube:

algorithm:

- Brute force: take each element and traverse through the whole array and
  check if the element occurs again, if yes, return true.
- TC: O(n^2)

- Better: Sort the array and check if adjacent elements are same, if
  yes, return true.
- TC: O(nlogn)

- Optimal: Using map, traverse through every element, and increment its
  frequency. Check if its frequency > 0, f yes, return true.

- Or use set, and check if the current element is already inserted
  into the set.

*/

/*

217. Contains Duplicate

Given an integer array nums, return true if any value appears at least
twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

*/

/*
************* Java Code **************

  public static boolean containsDuplicate(int[] nums) {
      Set<Integer> seen = new HashSet<>();
      for (int num : nums) {
          if (seen.contains(num)) {
              return true;
          }
          seen.add(num);
      }
      return false;
  }

*/