#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int minHeightShelvesRecur(int ind, int currWidth, int maxHeight, int shelfWidth, int n, vector<vector<int>> &books)
    {
        if (ind == n)
            return maxHeight;

        int pick = 1e9;
        int bookW = books[ind][0];
        int bookH = books[ind][1];

        if (currWidth + bookW <= shelfWidth)
        {
            int newHeight = max(maxHeight, bookH);
            pick = minHeightShelvesRecur(ind + 1, currWidth + bookW, newHeight, shelfWidth, n, books);
        }
        int notPick = maxHeight + minHeightShelvesRecur(ind + 1, bookW, bookH, shelfWidth, n, books);
        return min(pick, notPick);
    }
    // Memoization
    // int dp[1001][1001];   // compiler doesnt work for size 1000 array
    int minHeightShelvesMem(int ind, int currWidth, int maxHeight, int shelfWidth, int n, vector<vector<int>> &books, vector<vector<int>> &dp)
    {
        if (ind == n)
            return maxHeight;
        if (dp[ind][currWidth] != -1)
            return dp[ind][currWidth];

        int pick = 1e9;
        int bookW = books[ind][0];
        int bookH = books[ind][1];
        // case 1: Keeping the book in the same shelf
        if (currWidth + bookW <= shelfWidth)
        {
            int newHeight = max(maxHeight, bookH);
            pick = minHeightShelvesMem(ind + 1, currWidth + bookW, newHeight, shelfWidth, n, books, dp);
        }
        // case 2: new shelf to
        int notPick = maxHeight + minHeightShelvesMem(ind + 1, bookW, bookH, shelfWidth, n, books, dp);
        return dp[ind][currWidth] = min(pick, notPick);
    }
    // Tabulation

    // Space Optimization

    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        // return minHeightShelvesRecur(0, 0, 0, shelfWidth, n, books);
        // memset(dp, -1, sizeof(dp));
        vector<vector<int>> dp(n + 1, vector<int>(shelfWidth + 1, -1));
        return minHeightShelvesMem(0, 0, 0, shelfWidth, n, books, dp);
    }
};
int main()
{
    Solution s;
    vector<vector<int>> books{{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
    int shelfWidth = 4;
    // vector<vector<int>> books{{1, 3}, {2, 4}, {3, 2}};
    // int shelfWidth = 6;
    cout << "Result: " << s.minHeightShelves(books, shelfWidth) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/filling-bookcase-shelves

Youtube: https://www.youtube.com/watch?v=pOtAvGIW8kQ

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Filling%20Bookcase%20Shelves.cpp

algorithm:

- Optimal Approach:

- Use recursion and them memoize the solution.
- Similar to knapsack problem.
- Its given, we have to store the books, in the same, as per given in the array.
- We take 2 decisions, whether to keep the current book in the same shelf or create a new shelf and
  store it.
- Case 1:
- We can keep the current book in the current shelf, only if there is enough width available.
- If yes, then we keep it and move to next book. In this case, the new width = (currWidth + bookW).
- And the height will be the max height of the books present in that shelf = max(maxHeight, bookH).
- Why only taking max height? since thats what mentioned in the problem, to always take max height 
  as the height of the current shelf.

- Case 2:
- If not, then we keep the book in the new shelf. and then move to next book.
- In this case, the new width will be the width of the current book, sinvce thats the only
  book present in the newly created shelf.
- Here we add the maxheight of the current shelf into the result, since thats the final height
  of the current shelf. The total addight of these maxheight of each shelf will be our final answer.
- And we move to the next book, with the bookH as the new height.

*/

/*

1105. Filling Bookcase Shelves

You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and
height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than
or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total
height of the bookcase has increased by the maximum height of the books we just put down. We
repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as
the given sequence of books.

For example, if we have an ordered list of 5 books, we might place the first and second book onto
the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

Example 1:

Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.

Example 2:

Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
Output: 4

Constraints:

1 <= books.length <= 1000
1 <= thicknessi <= shelfWidth <= 1000
1 <= heighti <= 1000

*/

/*
************* Java Code **************

    private static int n;
    private static int width;
    private static int[][] dp;

    public static int minHeightShelvesMem(int ind, int currWidth, int maxHeight, int[][] books) {
        if (ind == n)
            return maxHeight;
        if (dp[ind][currWidth] != -1)
            return dp[ind][currWidth];

        int pick = Integer.MAX_VALUE;
        int bookW = books[ind][0];
        int bookH = books[ind][1];
        
        if (currWidth + bookW <= width) {
            int newHeight = Math.max(maxHeight, bookH);
            pick = minHeightShelvesMem(ind + 1, currWidth + bookW, newHeight, books);
        }
        int notPick = maxHeight + minHeightShelvesMem(ind + 1, bookW, bookH, books);
        return dp[ind][currWidth] = Math.min(pick, notPick);
    }

    public static int minHeightShelves(int[][] books, int shelfWidth) {
        n = books.length;
        width = shelfWidth;
        dp = new int[n + 1][shelfWidth + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return minHeightShelvesMem(0, 0, 0, books);
    }

*/