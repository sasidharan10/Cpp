#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
bool arePair(char open, char close)
{
    if (open == '{' && close == '}')
        return true;
    else if (open == '(' && close == ')')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else
        return false;
}
bool isBalanced(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            s.push(str[i]);
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if (!s.empty() && arePair(s.top(), str[i]))
                s.pop();
            else
                return false;
        }
    }
    return s.empty() ? true : false;
}
int main()
{
    string expr = "{()}[]";

    // Function call
    if (isBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}