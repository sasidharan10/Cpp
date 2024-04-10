#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    vector<int> deckRevealedIncreasing2(vector<int> &deck)
    {
        // TC: O(nlogn) + O(nlogn)
        // SC: O(n)

        int n = deck.size();
        vector<int> res(n, 0);
        sort(deck.begin(), deck.end());
        int i = 0, j = 0;
        bool skip = false;
        while (i < n)
        {
            if (res[j] == 0)
            {
                if (skip == false)
                {
                    res[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }
            j = (j + 1) % n;
        }
        return res;
    }

    // Optimal - queue simulation
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        // TC: O(nlogn)
        // SC: O(n)
        
        int n = deck.size();
        vector<int> res(n, 0);
        queue<int> que;
        sort(deck.begin(), deck.end());
        for (int i = 0; i < n; i++)
        {
            que.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            int idx = que.front();
            que.pop();
            res[idx] = deck[i];

            if (!que.empty())
            {
                que.push(que.front());
                que.pop();
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{17, 13, 11, 2, 3, 5, 7};
    vector<int> ans = s.deckRevealedIncreasing(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reveal-cards-in-increasing-order/

Youtube: https://www.youtube.com/watch?v=S6MGVmkMz2c

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

950. Reveal Cards In Increasing Order

You are given an integer array deck. There is a deck of cards where every card
has a unique integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start
face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.

Example 1:

Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation:
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.

Example 2:

Input: deck = [1,1000]
Output: [1,1000]

*/

/*
************* Java Code **************

public static int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        int[] res = new int[n];
        Queue<Integer> que = new LinkedList<>();
        Arrays.sort(deck);
        for (int i = 0; i < n; i++) {
            que.offer(i);
        }
        for (int i = 0; i < n; i++) {
            int idx = que.poll();
            res[idx] = deck[i];

            if (!que.isEmpty()) {
                que.offer(que.poll());
            }
        }
        return res;
    }

*/