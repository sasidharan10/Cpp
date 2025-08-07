#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    // Brute force - Gives TLE
    int findDuplicate5(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                    return nums[i];
            }
        }
        return -1;
    }

    // Better - Sorting the array (Accepted)
    int findDuplicate4(vector<int> &nums)
    {
        // TC: O(nlogn)
        // SC: O(1)

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }
        return -1;
    }

    // Better - using map to mark the visited numbers
    int findDuplicate3(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<bool> mp(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            if (mp[nums[i]])
                return nums[i];
            mp[nums[i]] = true;
        }
        return -1;
    }

    // if modifying array is allowed
    int findDuplicate2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int ind = abs(nums[i]);
            if (nums[ind] < 0)
                return ind;
            nums[ind] = -nums[ind];
        }
        return -1;
    }

    // Optimal - using floyd cycle detection
    int findDuplicate(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 3, 4, 2, 2};
    cout << "Duplicate: " << s.findDuplicate3(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-duplicate-number/

Youtube: https://www.youtube.com/watch?v=wjYnzkAhcNk

algorithm:

- Brute Force Approach:

- Sorting and finding if adjacent element is same
- using map to check duplicate elements

- Optimal Approach:

- Since the given umbers are from the range 1 - n. we can use the
  numbers as index and mark as -ve at that index.
- If that index is already marked, then its a duplicate number.
- while marking the index, we take ind = ind - 1. since the range is 1 to n, and the
  index range  is 0 to n - 1.

- Floyd cycle detection
- We find the index, where the cycle occurs.
- then initialize slow = 0, then move slow, fast by 1 index, until they meet.
- The intersection value is the duplicate element.

*/