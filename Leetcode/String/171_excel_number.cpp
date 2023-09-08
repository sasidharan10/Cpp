#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int sum = 0;
        int i = 0;
        while (columnTitle.length() > i)
        {
            int temp = columnTitle[i] - 64;
            sum = sum * 26 + temp;
            i++;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    string str = "ZY";
    cout << "Value: " << s.titleToNumber(str);
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/excel-sheet-column-number/description/

Youtube: https://www.youtube.com/watch?v=_NqvWkRN3Dc

algorithm: 

*/