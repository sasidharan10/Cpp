#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool IsOperator(char c)
{
    if(c=='+' ||c=='-' ||c=='*' ||c=='/' ||c=='^')
        return true;
    else 
        return false;
}
bool IsOperand(char c)
{
    if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9')
        return true;
    else
        return false;
}
int GetWeight(char c)
{
    int w=-1;
    switch (c)
    {
    case '-':
    case '+':  w=1;  
        break;
    case '*':
    case '/':  w=2;   
        break;
    case '^':  w=3; 
        break;
    }
    return w;
}
bool IsRight(char c)
{
    if(c=='^')
        return true;
    else
        return false;
}
bool HigherPrecedence(char a,char b)
{
    int w1=GetWeight(a);
    int w2=GetWeight(b);
    if(w1==w2)
    {
        if(IsRight(a))
            return true;
        else
            return false;
    }
    return w1>w2 ? true : false;
}
string PostFix(string a)
{
    stack<char> s;
    string b="";
    for(int i=0;i<=a.length();i++)
    {
        if(a[i]==' ' || a[i]==',')
            continue;
        else if(IsOperand(a[i]))
        {
            b+=a[i];
        }
        else if(IsOperator(a[i]))
        {
            while(!s.empty() && HigherPrecedence(s.top(),a[i]) && s.top()!='(')
            {
                b+=s.top();
                s.pop();
            }
            s.push(a[i]);
        }
        else if(a[i]=='(')
        {
            s.push(a[i]);
        }
        else if(a[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                b+=s.top();
                s.pop();
            }
            s.pop();
        }
        else if(!s.empty())
        {
            b+=s.top();
            s.pop();
        }
    }
    return b;
}
int main()
{
    string a="a*(b+c)";
    string b=PostFix(a);
    cout<<"Postfix : "<<b;
    return 0;
}

