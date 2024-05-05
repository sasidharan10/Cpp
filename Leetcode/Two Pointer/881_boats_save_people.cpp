#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        // TC: O(nlogn) + O(n)
        // SC: O(1)

        int n = people.size();
        int boats = 0;
        sort(people.begin(), people.end());
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++;
                j--;
                boats++;
            }
            else
            {
                j--;
                boats++;
            }
        }
        if (i == j)
            return boats + 1;
        else
            return boats;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{3, 2, 2, 1};
    // int limit = 3;
    vector<int> nums{1, 6, 4, 9};
    int limit = 10;
    cout << "Result: " << s.numRescueBoats(nums, limit) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/boats-to-save-people/

Youtube: https://www.youtube.com/watch?v=UsQzOL6r0HY

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Greedy/Boats%20to%20Save%20People.cpp

algorithm:

- Optimal Approach:

- The weight of any person will always be <= limit.
- Only 1 or 2 people can travel in a boat given their weight <= limit.
- So, we need to make as amany pairs as possible, whole weight <= limit.
- Hence we sort the array first. 
- Then we try to pair the heaviest guy with the lightest guy, and check if
  sum(weight) <= limit, if yes, then we pair them and move on to next guys.
- If sum(weight) > limit, then its clear that, the heaviest can never travel in pair, since
- He cannnot pair with the lightest guy, so all other options are also not possible.

*/

/*

881. Boats to Save People

You are given an array people where people[i] is the weight of the ith person,
and an infinite number of boats where each boat can carry a maximum weight of limit.
Each boat carries at most two people at the same time, provided the sum of the weight
of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)

*/

/*
************* Java Code **************

public int numRescueBoats(int[] people, int limit) {
        int n = people.length;
        int boats = 0;
        Arrays.sort(people);
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++;
                j--;
                boats++;
            }
            else
            {
                j--;
                boats++;
            }
        }
        if (i == j)
            return boats + 1;
        else
            return boats;
    }

*/