#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;
int frogJumpRecur(int n, int k, vector<int> &heights)
{
    if (n == 0)
        return 0;
    int minJump = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int temp = INT_MAX;
        if (n - i >= 0)
        {
            temp += frogJumpRecur(n - i, k, heights) + abs(heights[n] - heights[n - i]);
        }
        minJump = min(temp, minJump);
    }
    return minJump;
}
int frogJump(int n, int k, vector<int> &heights)
{
    return frogJumpRecur(n - 1, k, heights);
}
int main()
{
    int n = 4;
    int k = 2;
    vector<int> height{10, 20, 30, 10};
    cout << "Least Energy spent: " << frogJump(n, k, height);
    return 0;
}

/*

link: 

leetcode: 

Youtube: https://www.youtube.com/watch?v=Kmh3rhyEtB8&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=5

algorithm: 

*/