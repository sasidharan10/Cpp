#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        // TC: O(n) + O(n)
        // SC: O(1)
        
        int n = customers.size();
        int curr = 0;
        for (int i = 0; i < minutes; i++)
        {
            if (grumpy[i] == 1)
                curr += customers[i];
        }
        int maxi = curr;
        int i = 0, j = minutes;
        while (j < n)
        {
            if (grumpy[j] == 1)
                curr += customers[j];
            if (grumpy[i] == 1)
                curr -= customers[i];
            maxi = max(maxi, curr);
            i++;
            j++;
        }

        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
                maxi += customers[i];
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5}, grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    // vector<int> customers = {3, 7}, grumpy = {0, 0};
    // int minutes = 2;
    cout << "Result: " << s.maxSatisfied(customers, grumpy, minutes) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/grumpy-bookstore-owner

Youtube: https://www.youtube.com/watch?v=kCxCE0_66vM

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Grumpy%20Bookstore%20Owner.cpp

algorithm:

- Optimal Approach:

- when grumpy[i] = 0, the customers are satisfied, and vice-versa.
- We can make only make m(or minutes) consecutive minutes of grumpy array as 0.
- We need to find the subaray of size m, which when converted to 0, will
  yield max customer satisfaction.
- So we take a sliding window of size "minutes" and slide through the customers array
  and add only customers[i], when grumpy[i] == 1, since we need to find the subarray,
  not only with max customers, but with  grumpy array having max no of 1's to yield the best result.
- once we get the max customers, in the "maxi" variable, we will loop thorugh again and 
  all the customers, when grumpy[i] == 0, and return the result.

*/

/*

1052. Grumpy Bookstore Owner

There is a bookstore owner that has a store open for n minutes. Every minute,
some number of customers enter the store. You are given an integer array customers
of length n where customers[i] is the number of the customer that enters the store
at the start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy
where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied,
otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes
consecutive minutes, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes.
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

Example 2:

Input: customers = [1], grumpy = [0], minutes = 1
Output: 1

Constraints:

n == customers.length == grumpy.length
1 <= minutes <= n <= 2 * 104
0 <= customers[i] <= 1000
grumpy[i] is either 0 or 1.

*/

/*
************* Java Code **************

public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = customers.length;
        int curr = 0;
        for (int i = 0; i < minutes; i++)
        {
            if (grumpy[i] == 1)
                curr += customers[i];
        }
        int maxi = curr;
        int i = 0, j = minutes;
        while (j < n)
        {
            if (grumpy[j] == 1)
                curr += customers[j];
            if (grumpy[i] == 1)
                curr -= customers[i];
            maxi = Math.max(maxi, curr);
            i++;
            j++;
        }

        for (i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
                maxi += customers[i];
        }
        return maxi;
    }

*/