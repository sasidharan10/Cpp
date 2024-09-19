#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // creating substr and computing
    vector<int> solve2(string str)
    {
        // T.C : O(n*2^n) *n // extra time for creating substring
        // S.C : O(2^n)      // space for storing all the results.

        int n = str.length();
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*')
            {
                vector<int> lt = solve2(str.substr(0, i));
                vector<int> rt = solve2(str.substr(i + 1));

                for (int &x : lt)
                {
                    for (int &y : rt)
                    {
                        if (str[i] == '+')
                            res.push_back(x + y);
                        else if (str[i] == '-')
                            res.push_back(x - y);
                        else
                            res.push_back(x * y);
                    }
                }
            }
        }

        if (res.empty())
            res.push_back(stoi(str));

        return res;
    }

    // without using substr()
    vector<int> solve(string &str, int start, int end)
    {
        // T.C : O(n*2^n)
        // S.C : O(2^n)

        if (end == start)
            return {str[start] - '0'};

        // if number is of double digit
        if (end - start == 1)
            return {((str[start] - '0') * 10) + (str[end] - '0')};

        vector<int> res;
        for (int i = start; i <= end; i++)
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*')
            {
                vector<int> lt = solve(str, start, i - 1);
                vector<int> rt = solve(str, i + 1, end);

                for (int &x : lt)
                {
                    for (int &y : rt)
                    {
                        if (str[i] == '+')
                            res.push_back(x + y);
                        else if (str[i] == '-')
                            res.push_back(x - y);
                        else
                            res.push_back(x * y);
                    }
                }
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression)
    {
        int n = expression.length();
        // return solve2(expression);
        return solve(expression, 0, n - 1);
    }
};
int main()
{
    Solution s;
    string str = "2*3-4*5";
    vector<int> ans = s.diffWaysToCompute(str);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/different-ways-to-add-parentheses

Youtube: https://www.youtube.com/watch?v=vWW67t_a--8

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Recursion/Different%20Ways%20to%20Add%20Parentheses.cpp

algorithm:

- Optimal Approach:

- Using recursion, we find all possible results and return the list.
- As we traverse through the string, we split it into 2 string, as soon as we encounter
  an operator.
- Then these string will further gets splited, and computed.
- We get 2 lists, after computation.
- Then we compute all possible combination, and store the resutls in a result and return it.

- In optimal approach, we use pointers to iterate the sub strings, instead of creating new substring
  hence, reducing the space complexity.

*/

/*

241. Different Ways to Add Parentheses

Given a string expression of numbers and operators, return all possible results from computing
all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number
of different results does not exceed 104.

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2

Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].

*/

/*
************* Java Code **************

    public static List<Integer> solve(String str, int start, int end) {
        if (end == start)
            return new ArrayList<>(Arrays.asList(str.charAt(start) - '0'));

        // if number is of double digit
        if (end - start == 1)
            return new ArrayList<>(Arrays.asList(((str.charAt(start) - '0') * 10) + (str.charAt(end) - '0')));

        List<Integer> res = new ArrayList<>();
        for (int i = start; i <= end; i++) {
            if (str.charAt(i) == '+' || str.charAt(i) == '-' || str.charAt(i) == '*') {
                List<Integer> lt = solve(str, start, i - 1);
                List<Integer> rt = solve(str, i + 1, end);

                for (int x : lt) {
                    for (int y : rt) {
                        if (str.charAt(i) == '+')
                            res.add(x + y);
                        else if (str.charAt(i) == '-')
                            res.add(x - y);
                        else
                            res.add(x * y);
                    }
                }
            }
        }
        return res;
    }

    public static List<Integer> diffWaysToCompute(String expression) {
        int n = expression.length();
        return solve(expression, 0, n - 1);
    }

*/