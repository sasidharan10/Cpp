#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        if (M > N)
            return -1;
        int sunday = S / 7;
        int buyingDays = S - sunday;
        int totalFood = S * M;
        int requiredDays = 0;
        if (totalFood % N == 0)
        {
            requiredDays = totalFood / N;
        }
        else
        {
            requiredDays = (totalFood / N) + 1;
        }
        if (requiredDays <= buyingDays)
            return requiredDays;
        else
            return -1;
    }
};
int main()
{
    Solution s;
    int S = 10, N = 16, M = 2;
    cout << "Minimum no of days, to buy food, inorder to survive: " << s.minimumDays(S, N, M) << endl;
    return 0;
}