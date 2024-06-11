#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal - using vector as map since range [1, 1000].
    vector<int> relativeSortArray2(vector<int> &arr1, vector<int> &arr2)
    {
        // TC: O(n) + O(m) + O(1000)
        // SC: O(1000) + O(n)

        int n = arr1.size();
        int m = arr2.size();
        vector<int> mp(1001, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            mp[arr1[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            int idx = arr2[i];
            while (mp[idx])
            {
                ans.push_back(idx);
                mp[idx]--;
            }
        }
        for (int i = 0; i < 1001; i++)
        {
            while (mp[i])
            {
                ans.push_back(i);
                mp[i]--;
            }
        }
        return ans;
    }

    // Optimal - using custom sort(lambda function)
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        // TC: O(nlogn)
        // SC: O(n)

        int n = arr1.size();
        int m = arr2.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            mp[arr2[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            // if (!mp.count(arr1[i]))
            if (mp.find(arr1[i]) == mp.end())
                mp[arr1[i]] = 1e9;
        }

        // [&] is used to access all accessible variables inside the lambda function.
        auto lambda = [&](int &idx1, int &idx2)
        {
            if (mp[idx1] == mp[idx2])
                return idx1 < idx2;
            return mp[idx1] < mp[idx2];
        };

        sort(arr1.begin(), arr1.end(), lambda);
        return arr1;
    }
};
int main()
{
    Solution s;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> ans = s.relativeSortArray(arr1, arr2);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/relative-sort-array

Youtube: https://www.youtube.com/watch?v=Yz202siZDHA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Relative%20Sort%20Array.cpp

algorithm:

- Optimal Approach:

- Using ordered map to get frequencies of all arr1 elements.
- traversing in arr2, and checking if that element present in map, if yes, then push
  that elements as per its frequency.
- Finally, traversing the map, and adding the remaining elements present in the map,
  into the resultant array, maintainng the order.

- Using custom map.

*/

/*

1122. Relative Sort Array

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements
in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the
same as in arr2. Elements that do not appear in arr2 should be placed at the end
of arr1 in ascending order.

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]

Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.

*/

/*
************* Java Code **************

public static int[] relativeSortArray(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int m = arr2.length;
        int[] mp = new int[1001];
        int[] ans = new int[n];
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            mp[arr1[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            int idx = arr2[i];
            while (mp[idx]>0)
            {
                ans[index++] = idx;
                mp[idx]--;
            }
        }
        for (int i = 0; i < 1001; i++)
        {
            while (mp[i] > 0)
            {
                ans[index++] = i;
                mp[i]--;
            }
        }
        return ans;
    }

    public static int[] relativeSortArray(int[] arr1, int[] arr2) {
        // Create a map to store the index of each element in arr2
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr2.length; i++) {
            map.put(arr2[i], i);
        }

        // Mark elements not in arr2 with a large value (to be sorted at the end)
        int largeValue = 1000000000; // 1e9 equivalent in Java
        for (int i = 0; i < arr1.length; i++) {
            if (!map.containsKey(arr1[i])) {
                map.put(arr1[i], largeValue);
            }
        }

        // Define the comparator using a lambda expression
        Comparator<Integer> comparator = (num1, num2) -> {
            int index1 = map.get(num1);
            int index2 = map.get(num2);
            if (index1 == index2) {
                return Integer.compare(num1, num2);
            }
            return Integer.compare(index1, index2);
        };

        // Convert arr1 to a list for sorting
        List<Integer> arr1List = new ArrayList<>();
        for (int num : arr1) {
            arr1List.add(num);
        }

        // Sort the list using the defined comparator
        Collections.sort(arr1List, comparator);

        // Convert the sorted list back to an array
        int[] sortedArray = new int[arr1.length];
        for (int i = 0; i < arr1.length; i++) {
            sortedArray[i] = arr1List.get(i);
        }

        return sortedArray;
    }
    
*/