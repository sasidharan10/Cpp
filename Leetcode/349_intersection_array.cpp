#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    //Approach-1 (Using two sets)
    vector<int> intersection3(vector<int> &nums1, vector<int> &nums2)
    {
        // TC : O(m+n)
        // SC : O(m+n)

        int n = nums1.size();
        int m = nums2.size();

        unordered_set<int> st1(nums1.begin(), nums1.end()), st2;
        for (int i = 0; i < m; i++)
        {
            if (st1.find(nums2[i]) != st1.end())
            {
                st2.insert(nums2[i]);
            }
        }

        vector<int> ans(st2.begin(), st2.end());
        return ans;
    }

    //Approach-2 (Using one set)
    vector<int> intersection2(vector<int> &nums1, vector<int> &nums2)
    {
        // TC : O(m+n)
        // SC : O(m+n)

        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;
        unordered_set<int> st(nums1.begin(), nums1.end());
        for (int i = 0; i < m; i++)
        {
            if (st.empty())
                break;
            if (st.find(nums2[i]) != st.end())
            {
                ans.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }
        return ans;
    }

    //Approach-3 (Sorting and two-pointers)
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // TC: O(nlogn) + O(mlogm) + O(m + n)
        // SC: O(1)

        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);

                while (i < n - 1 && nums1[i] == nums1[i + 1])
                    i++;

                while (j < m - 1 && nums2[j] == nums2[j + 1])
                    j++;

                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> a{4, 9, 5};
    vector<int> b{9, 4, 9, 8, 4};
    vector<int> ans = s.intersection(a, b);
    cout << "Intersection: ";
    for (int i : ans)
        cout << i << " ";
}

/*

link: 

leetcode: https://leetcode.com/problems/intersection-of-two-arrays/

Youtube: https://www.youtube.com/watch?v=rqPu9ZvLdi0

code: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Intersection%20of%20Two%20Arrays.cpp

algorithm: 

*/

/*

349. Intersection of Two Arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

*/


/*

public static int[] intersection(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        List<Integer> ans = new ArrayList<>();

        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                ans.add(nums1[i]);

                while (i < n - 1 && nums1[i] == nums1[i + 1])
                    i++;

                while (j < m - 1 && nums2[j] == nums2[j + 1])
                    j++;

                i++;
                j++;
            } else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }

*/