#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = prices.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() > prices[i])
            {
                st.pop();
            }
            if (st.empty())
                ans[i] = prices[i];
            else
                ans[i] = prices[i] - st.top();
            st.push(prices[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{8, 4, 6, 2, 3};
    // vector<int> nums{1, 2, 3, 4, 5};
    vector<int> ans = s.finalPrices(nums);
    cout << "Final Prices of all items after Special Discount: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

Youtube:

algorithm:

- Brute force: Find next smaller element of each element, searching from
  i to n. If no smaller element found, keep the same price.
- Next smaller element variation.
- Monotonic stack(maintains decreasing order).
- in case of next smaller element algorithm, we keep the stack such that,
  it maintains decreasing order, so everytime i pop() 1 element from
  the stack, i get much smaller element. If i found no smaller element
  the the stack is empty(), then current element is the smaller element.

*/

/*

1475. Final Prices With a Special Discount in a Shop

You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount for items in the shop. If you buy the ith item,
then you will receive a discount equivalent to prices[j] where j is the
minimum index such that j > i and prices[j] <= prices[i]. Otherwise,
you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will
pay for the ith item of the shop, considering the special discount.

Example 1:

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation:
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4,
therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2,
therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2,
therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
Example 2:

Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.
Example 3:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]


*/