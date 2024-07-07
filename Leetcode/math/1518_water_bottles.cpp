#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int numWaterBottles3(int numBottles, int numExchange)
    {
        // TC: O(n)
        // SC: O(1)

        int emptyBottles = numBottles;
        int consumed = 0;
        while (numBottles >= numExchange)
        {
            numBottles -= numExchange;
            consumed += numExchange;
            numBottles++;
        }
        return consumed + numBottles;
    }

    // Better
    int numWaterBottles2(int numBottles, int numExchange)
    {
        // TC: O(logn)
        // SC: O(1)

        int emptyBottles = numBottles;
        int consumed = numBottles;
        while (emptyBottles >= numExchange)
        {
            consumed += emptyBottles / numExchange;
            emptyBottles = emptyBottles / numExchange + emptyBottles % numExchange;
        }
        return consumed;
    }

    // Optimal
    int numWaterBottles(int numBottles, int numExchange)
    {
        // TC: O(1)
        // SC: O(1)

        // int consumed = numBottles;
        // consumed += numBottles / (numExchange - 1);
        // if (numBottles % (numExchange - 1) == 0)
        //     consumed--;

        int consumed = numBottles + ((numBottles - 1) / (numExchange - 1));
        return consumed;
    }
};
int main()
{
    Solution s;
    int numBottles = 15, numExchange = 4;
    cout << "Result: " << s.numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/water-bottles

Youtube: https://www.youtube.com/watch?v=v2D_v3llC98

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Mathematical/Leetcode%20Easy/Water%20Bottles.cpp

algorithm:

- Optimal Approach:

- refer video

*/

/*

1518. Water Bottles

There are numBottles water bottles that are initially full of water. You can exchange
numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water
bottles you can drink.

Example 1:

Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.

Example 2:

Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 15 + 3 + 1 = 19.

Constraints:

1 <= numBottles <= 100
2 <= numExchange <= 100

*/

/*
************* Java Code **************

public int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles + ((numBottles - 1) / (numExchange - 1));
        return consumed;
    }

*/