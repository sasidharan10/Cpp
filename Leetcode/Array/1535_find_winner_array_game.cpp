#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotateLeft(vector<int>::iterator i, vector<int>::iterator j)
    {
        while (i < j)
        {
            swap(*i, *j);
            j--;
        }
    }
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        if (k >= n)
            return maxi;
        int winner = arr[0];
        int wins = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > winner)
            {
                wins = 1;
                winner = arr[i];
            }
            else
                wins++;
            if (k == wins || winner == maxi)
                return winner;
        }
        return winner;
    }
};
int main()
{
    Solution s;
    int k = 2;
    vector<int> nums{2, 1, 3, 5, 4, 6, 7};
    cout << "Winner: " << s.getWinner(nums, k);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-winner-of-an-array-game

Youtube:

algorithm:

*/