#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - simulating the game using vector
    int findTheWinner3(int n, int k)
    {
        // TC: O(n^2)
        // SC: O(n)

        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        int idx = 0;
        while (arr.size() > 1) // O(n)
        {
            idx = (idx + k - 1) % arr.size();
            arr.erase(arr.begin() + idx); // O(n)
        }
        return arr[0];
    }

    // Better - Using queue
    int findTheWinner2(int n, int k)
    {
        // TC: O(n*k)
        // SC: O(n)

        queue<int> que;
        for (int i = 1; i <= n; i++)
        {
            que.push(i);
        }
        while (que.size() > 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                que.push(que.front());
                que.pop();
            }
            que.pop();
        }
        return que.front();
    }

    // Optimal - using recursion
    int solve(int n, int k)
    {
        if (n == 1)
            return 0;
        int idx = solve(n - 1, k);
        return (idx + k) % n;
    }
    int findTheWinner(int n, int k)
    {
        int resultIndex = solve(n, k);
        return resultIndex + 1;
    }
};
int main()
{
    Solution s;
    int n = 5, k = 2;
    cout << "Result: " << s.findTheWinner(n, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-winner-of-the-circular-game

Youtube: https://www.youtube.com/watch?v=lq3RMxKST-Y

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Recursion/Find%20the%20Winner%20of%20the%20Circular%20Game.cpp

algorithm:

- Brute Force Approach:

- Silumation using vercot.

- Optimal Approach:

- refer video.

*/

/*

1823. Find the Winner of the Circular Game

There are n friends that are playing a game. The friends are sitting in a circle and are
numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend
brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend
brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at.
The counting wraps around the circle and may count some friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the
friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.

Example 1:

Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.

Example 2:

Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.

Constraints:

1 <= k <= n <= 500

*/

/*
************* Java Code **************

    public int findTheWinner(int n, int k) {
        Queue<Integer> que = new LinkedList<>();
        for (int i = 1; i <= n; i++)
        {
            que.offer(i);
        }
        while (que.size() > 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                que.offer(que.poll());
            }
            que.poll();
        }
        return que.peek();
    }

*/