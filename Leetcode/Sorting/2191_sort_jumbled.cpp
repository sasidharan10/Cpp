#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getValue2(int num, vector<int> &mapping)
    {
        string temp = to_string(num);    //O(d)
        int n = temp.length();
        for (int i = 0; i < n; i++)
        {
            temp[i] = mapping[temp[i] - '0'] + '0';
        }
        int res = stoi(temp);     //O(d)
        return res;
    }

    // better - converting the numbers into strings, to map them.
    vector<int> sortJumbled2(vector<int> &mapping, vector<int> &nums)
    {
        // TC: O(n*d)
        // SC: O(n + d)
        
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int num = getValue2(nums[i], mapping);
            mp[nums[i]] = num;
        }

        auto lambda = [&](int &a, int &b)
        {
            return mp[a] < mp[b];
        };

        sort(nums.begin(), nums.end(), lambda);
        return nums;
    }

    int getValue(int num, vector<int> &mapping)
    {
        if(num < 10)
            return mapping[num];
        int res = 0;
        int power = 1;
        while (num > 0)
        {
            int rem = num % 10;
            num /= 10;
            res += mapping[rem] * power;
            power *= 10;
        }
        return res;
    }

    // Optimal - mapping numbers by converting into strings.
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = nums.size();
        vector<pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            int num = getValue(nums[i], mapping);
            mp.push_back({num, i});
        }
        sort(mp.begin(), mp.end());
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            int idx = mp[i].second;
            res.push_back(nums[idx]);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6}, nums = {991, 338, 38};
    vector<int> ans = s.sortJumbled2(mapping, nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sort-the-jumbled-numbers/

Youtube: https://www.youtube.com/watch?v=BXHWgX4UX04

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Sort%20the%20Jumbled%20Numbers.cpp

algorithm:

- Better Approach:

- To convert the numbers w.r.t to the mappings, we convert the numbers into strings, then
  we do the mapping and get the new number.
- We use a map to store the old and new number.
- Using this map, we sort the nums array, with the help of the lambda function. 
  
- Optimal Approach:

- Instead of converting the numbers into strings, we can directly make the new numbers.
- Hence, we save the O(d) time using this approach.
- Other than that, everything else is same.
- In first approach, we used the map, to sort the nums array. Here we use we use 
  vector<pair<int, int>>, where we store {newNumber, originalIndex}.
- So when we sort it, it is sorted on the basis of new number. and if values are same, it 
  will sort based on the originalIndex. 
- Then we just have to iterate through that vector, in that same order, get the originalIndex
  and store the nums[originalIndex] in new array.
- return the new array.

*/

/*

2191. Sort the Jumbled Numbers

You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled 
decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of 
digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order 
based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.
 
Example 1:

Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
Output: [338,38,991]
Explanation: 
Map the number 991 as follows:
1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
Therefore, the mapped value of 991 is 669.
338 maps to 007, or 7 after removing the leading zeros.
38 maps to 07, which is also 7 after removing leading zeros.
Since 338 and 38 share the same mapped value, they should remain in the same relative order, 
so 338 comes before 38.
Thus, the sorted array is [338,38,991].

Example 2:

Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
Output: [123,456,789]
Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
 
Constraints:

mapping.length == 10
0 <= mapping[i] <= 9
All the values of mapping[i] are unique.
1 <= nums.length <= 3 * 10^4
0 <= nums[i] < 10^9

*/

/*
************* Java Code **************

    public static int getValue(int num, int[] mapping) {
        if (num < 10)
            return mapping[num];
        int res = 0;
        int power = 1;
        while (num > 0) {
            int rem = num % 10;
            num /= 10;
            res += mapping[rem] * power;
            power *= 10;
        }
        return res;
    }

    public static int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int num = getValue(nums[i], mapping);
            mp.putIfAbsent(nums[i], num);
        }

        Integer[] array = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        Comparator cmp = new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return Integer.compare(mp.get(a), mp.get(b));
            }
        };

        Arrays.sort(array, cmp);

        return Arrays.stream(array).mapToInt(Integer::intValue).toArray();
    }

*/