#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int sz = flowerbed.size();
        if (n == 0)
            return true;
        for (int i = 0; i < sz; i++)
        {
            if (i == 0)
            {
                // [0] || { 0, 0, 1, ...... }
                if (flowerbed[i] == 0 && (i + 1 >= sz || flowerbed[i + 1] == 0))
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (i == sz - 1)
            {
                // {......, 1, 0, 0}
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
            if (n <= 0)
                return true;
        }
        if (n > 0)
            return false;
        else
            return true;
    }
};
int main()
{
    Solution s;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    cout << "Can Place Flowers?: " << s.canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/can-place-flowers

Youtube:

algorithm:

*/

/*

605. Can Place Flowers

You have a long flowerbed in which some of the plots are planted, and some
are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty
and 1 means not empty, and an integer n, return true if n new flowers can be
planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.


Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false




*/