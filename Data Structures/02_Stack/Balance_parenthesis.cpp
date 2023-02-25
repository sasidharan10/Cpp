#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool arePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else
        return false;
}
bool areParenthesis(char *exp, int n)
{
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (!s.empty() && (arePair(s.top(), exp[i])))
                s.pop();
            else
                return false;
        }
    }
    return s.empty() ? true : false;
}
int main()
{
    char exp[] = {"{[(())]}"};
    cout << exp << endl;
    int n = sizeof(exp) / sizeof(exp[0]);
    if (areParenthesis(exp, n - 1))
        cout << "It is balanced.";
    else
        cout << "It is NOT balanced.";
    return 0;
}