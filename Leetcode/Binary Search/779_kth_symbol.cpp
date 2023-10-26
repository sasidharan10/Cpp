#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute
    int kthGrammar2(int n, int k)
    {
        // TC: O(2^n)
        // SC: O(2^n)

        string prev = "0", cur = "";
        for (int i = 0; i < n - 1; i++)
        {
            cur = "";
            for (int j = 0; j < prev.size(); j++)
            {
                if (prev[j] == '0')
                    cur += "01";
                else
                    cur += "10";
            }
            cout << cur << endl;
            prev = cur;
        }
        return prev[k - 1] - 48;
    }

    // optimal
    int kthGrammar(int n, int k)
    {
        // TC: O(n)
        // SC: O(1)

        int left = 1, right = pow(2, n - 1);
        int cur = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int mid = (left + right) / 2;
            if (k <= mid)
                right = mid;
            else
            {
                left = mid + 1;
                cur == 0 ? cur = 1 : cur = 0;
            }
        }
        return cur;
    }
};
int main()
{
    Solution s;
    int n = 3, k = 2;
    cout << "K-th Symbol in Grammar: " << s.kthGrammar(n, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/k-th-symbol-in-grammar

Youtube: https://www.youtube.com/watch?v=pmD2HCKaqRQ

algorithm:

- We traverse it like a tree and use binary search.
- The second half of the row is complement of the first half.

*/