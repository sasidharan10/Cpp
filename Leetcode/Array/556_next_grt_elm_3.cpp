#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string str = to_string(n);
        int len = str.length();
        int peak = -1, index = 0;
        // finding left element of peak element which is as right as possible
        for (int i = len - 2; i >= 0; i--)
        {
            if (str[i + 1] > str[i])
            {
                peak = i;
                break;
            }
        }
        if (peak == -1)
            return peak;

        for (int i = len - 1; i > peak; i--)
        {
            if (str[i] > str[peak])
            {
                index = i;
                break;
            }
        }
        swap(str[index], str[peak]);
        reverse(str.begin() + peak + 1, str.end());
        long int res = stol(str);
        if (res > INT_MAX)
            return -1;
        else
            return res;
    }
};
int main()
{
    Solution s;
    int n = 124651;
    cout << "Next Greater Number: " << s.nextGreaterElement(n);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/next-greater-element-iii/description/

Youtube:

algorithm: This is literally next permutaion problem

*/