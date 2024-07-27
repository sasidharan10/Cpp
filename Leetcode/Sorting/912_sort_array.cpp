#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - Merge sort
    void merge(vector<int> &nums, vector<int> &left, int l, vector<int> &right, int r)
    {
        int i = 0, j = 0, k = 0;
        while (i < l && j < r)
        {
            if (left[i] <= right[j])
            {
                nums[k] = left[i];
                i++;
            }
            else
            {
                nums[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < l)
        {
            nums[k] = left[i];
            k++;
            i++;
        }
        while (j < r)
        {
            nums[k] = right[j];
            k++;
            j++;
        }
    }
    void mergeSort(vector<int> &nums, int n)
    {
        if (n < 2)
            return;
        int mid = n / 2;
        vector<int> left(mid, 0);
        vector<int> right(n - mid, 0);
        for (int i = 0; i < mid; i++)
        {
            left[i] = nums[i];
        }
        for (int i = mid; i < n; i++)
        {
            right[i - mid] = nums[i];
        }
        mergeSort(left, mid);
        mergeSort(right, n - mid);
        merge(nums, left, mid, right, n - mid);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        // TC: O(nlogn)
        // SC: O(nlogn)
        
        int n = nums.size();
        mergeSort(nums, n);
        return nums;
    }

    // Better - heap sort
    void heapify(vector<int> &nums, int i, int n)
    {
        // TC: O(logn)
        // SC: O(1)
        
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && nums[left] > nums[i])
        {
            largest = left;
        }
        if (right < n && nums[right] > nums[largest])
        {
            largest = right;
        }
        if (i != largest)
        {
            swap(nums[i], nums[largest]);
            heapify(nums, largest, n);
        }
    }
    void heapSort(vector<int> &nums)
    {
        int n = nums.size();
        int start = (n / 2) - 1;
        for (int i = start; i >= 0; i--)
        {
            heapify(nums, i, n);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }
    }
    vector<int> sortArray2(vector<int> &nums)
    {
        // TC: O(nlogn)
        // SC: O(1)
        
        int n = nums.size();
        heapSort(nums);
        return nums;
    }

    // Optimal - Counting sort
    vector<int> sortArray3(vector<int> &nums)
    {
        // TC: O(maxi - mini)
        // SC: O(n)

        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int idx = 0;
        for (int i = mini; i <= maxi; i++)
        {
            while (mp[i] > 0)
            {
                nums[idx] = i;
                mp[i]--;
                idx++;
            }
        }
        return nums;
    }
};
int main()
{
    Solution s;
    vector<int> nums{5, 1, 1, 2, 0, 0};
    vector<int> ans = s.sortArray(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sort-an-array

Youtube: https://www.youtube.com/watch?v=PnyxRdn-N9U

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Sort%20an%20Array.cpp

algorithm:

- Optimal Approach:

- merge sort.
- heap sort.
- Counting sort.

*/

/*

912. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and
with the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed
(for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.

Constraints:

1 <= nums.length <= 5 * 10^4
-5 * 104 <= nums[i] <= 5 * 10^4

*/

/*
************* Java Code **************

    public static int[] sortArray(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            mini = Math.min(nums[i], mini);
            maxi = Math.max(nums[i], maxi);
        }

        int idx = 0;
        for (int i = mini; i <= maxi; i++) {
            while (mp.containsKey(i) && mp.get(i) > 0) {
                nums[idx] = i;
                mp.replace(i, mp.get(i) - 1);
                idx++;
            }
        }
        return nums;
    }

*/