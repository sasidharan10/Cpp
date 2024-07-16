#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string countOfAtoms(string formula)
    {
        // TC: O(n^2) + O(nlogn)
        // SC: O(n)

        int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i = 0;
        while (i < n)
        {
            if (formula[i] == '(')
            {
                st.push(unordered_map<string, int>());
                i++;
            }
            else if (formula[i] == ')')
            {
                unordered_map<string, int> currMap = st.top();
                st.pop();
                i++;
                int num = 0;
                while (i < n && isdigit(formula[i]))
                {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                if (num > 0)
                {
                    for (auto it : currMap) // O(n)
                    {
                        string element = it.first;
                        int cnt = it.second;
                        currMap[element] = cnt * num;
                    }
                }

                // merging with the top() map
                for (auto it : currMap) // O(n)
                {
                    string element = it.first;
                    int cnt = it.second;
                    st.top()[element] += cnt;
                }
            }
            else
            {
                string curr = "";
                curr += formula[i];
                i++;
                if (i < n && isalpha(formula[i]) && islower(formula[i]))
                {
                    curr += formula[i];
                    i++;
                }
                int num = 0;
                while (i < n && isdigit(formula[i]))
                {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                num = (num == 0) ? 1 : num;
                st.top()[curr] += num;
            }
        }

        map<string, int> sortedMap(st.top().begin(), st.top().end()); // O(nlogn)
        string res = "";
        for (auto it : sortedMap)
        {
            string element = it.first;
            int cnt = it.second;
            res += element;
            if (cnt > 1)
                res += to_string(cnt);
        }
        return res;
    }
};
int main()
{
    Solution s;
    string str = "K4(ON(SO3)2)2";
    cout << "Result: " << s.countOfAtoms(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-atoms

Youtube: https://www.youtube.com/watch?v=XnVWIT47H0Y

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Stack/Number%20of%20Atoms.cpp

algorithm:

- Optimal Approach:

- 

*/

/*

726. Number of Atoms

Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase
letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1.
If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order),
followed by its count (if that count is more than 1), followed by the second name (in sorted order),
followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.

Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

Constraints:

1 <= formula.length <= 1000
formula consists of English letters, digits, '(', and ')'.
formula is always valid.

*/

/*
************* Java Code **************

public static String countOfAtoms(String formula) {
        int n = formula.length();
        Stack<Map<String, Integer>> st = new Stack<>();
        st.push(new HashMap<String, Integer>());
        int i = 0;
        while (i < n) {
            if (formula.charAt(i) == '(') {
                st.push(new HashMap<String, Integer>());
                i++;
            } else if (formula.charAt(i) == ')') {
                Map<String, Integer> currMap = st.peek();
                st.pop();
                i++;
                int num = 0;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    num = num * 10 + (formula.charAt(i) - '0');
                    i++;
                }
                if (num > 0) {
                    for (String element : currMap.keySet()) // O(n)
                    {
                        int cnt = currMap.get(element);
                        currMap.put(element, cnt * num);
                    }
                }

                // merging with the top() map
                for (String element : currMap.keySet()) // O(n)
                {
                    int cnt = currMap.get(element);
                    st.peek().put(element, st.peek().getOrDefault(element, 0) + cnt);
                }
            } else {
                String curr = "";
                curr += formula.charAt(i);
                i++;
                if (i < n && Character.isAlphabetic(formula.charAt(i)) && Character.isLowerCase(formula.charAt(i))) {
                    curr += formula.charAt(i);
                    i++;
                }
                int num = 0;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    num = num * 10 + (formula.charAt(i) - '0');
                    i++;
                }
                num = (num == 0) ? 1 : num;
                st.peek().put(curr, st.peek().getOrDefault(curr, 0) + num);
            }
        }

        TreeMap<String, Integer> sortedMap = new TreeMap<>(st.peek()); // O(nlogn)
        StringBuilder res = new StringBuilder();
        for (String element : sortedMap.keySet()) {
            int cnt = sortedMap.get(element);
            res.append(element);
            if (cnt > 1)
                res.append(cnt);
        }
        return res.toString();
    }

*/