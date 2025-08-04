#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        // TC: O(nlogn)
        // SC: O(n)
        
        int n = nums.size();
        auto lamdba = [&](int &a, int &b)
        {
            string s1 = to_string(a);
            string s2 = to_string(b);
            return (s1 + s2) > (s2 + s1);
        };
        sort(nums.begin(), nums.end(), lamdba);

        // Edge case:
        if (nums[0] == 0)
            return "0";

        string res = "";
        for (int i = 0; i < n; i++)
        {
            res += to_string(nums[i]);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 30, 34, 5, 9};
    cout << "Result: " << s.largestNumber(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/largest-number

Youtube: https://www.youtube.com/watch?v=oJyl4fbfpM0

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Largest%20Number.cpp

algorithm:

- Optimal Approach:

- Sorting the array, based on its first digit.
- To do this, we use lambda function. Conver the number to string and then compare it.
- once sorted, append the numbers into a string and return it.

*/

/*

179. Largest Number

Given a list of non-negative integers nums, arrange them such that they form the largest number 
and return it.
Since the result may be very large, so you need to return a string instead of an integer.

Example 1:

Input: nums = [10,2]
Output: "210"

Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 
Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 10^9

*/

/*
************* Java Code **************

    public static String largestNumber(int[] nums) {
        int n = nums.length;
        Integer[] numsAsInteger = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Comparator cmp = new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                String s1 = Integer.toString(a);
                String s2 = Integer.toString(b);

                return (s2 + s1).compareTo(s1 + s2);
            }
        };
        // Arrays.sort(numsAsInteger, (a, b) -> {
        //     String s1 = Integer.toString(a);
        //     String s2 = Integer.toString(b);
        //     return (s2 + s1).compareTo(s1 + s2);
        // });

        Arrays.sort(numsAsInteger, cmp);

        // Edge case:
        if (numsAsInteger[0] == 0)
            return "0";

        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            res.append(numsAsInteger[i]);
        }
        return res.toString();
    }

*/