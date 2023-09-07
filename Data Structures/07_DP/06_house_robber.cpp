#include <bits/stdc++.h>
using namespace std;
int maximumNonAdjacentSumSpc(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i - 2 >= 0)
            pick += prev2;
        int notPick = 0 + prev;
        int cur = max(pick, notPick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1)
        return valueInHouse[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n - 1; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSumSpc(temp1), maximumNonAdjacentSumSpc(temp2));
}
int main()
{
    vector<int> v{1, 3, 2, 1};
    cout << "Maximum profit: " << houseRobber(v);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/house-robber_839733

leetcode: https://leetcode.com/problems/house-robber-ii/description/

Youtube: https://www.youtube.com/watch?v=3WaxQMELSkw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=7

algorithm: 

*/