#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isNumber(char c)
{
    if(c>='0' && c<='9')
        return true;
    else
        return false;
}
bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    else 
        return false;
}
int Operation(char oper,int op1,int op2)
{
    if(oper=='+') return op1+op2;
    if(oper=='-') return op1-op2;
    if(oper=='*') return op1*op2;
    if(oper=='/') return op1/op2;
    else
        cout<<"Unexpected Error!!!";
        return -1;
        
}

int postfixEvaluation(char* a,int n)
{
    stack<char> s;
    for(int i=0;i<n;i++)
    {
        if(a[i]==' ' || a[i]==',')
            continue;
        else if(isOperator(a[i]))
        {
            char op2=s.top();
            s.pop();
            char op1=s.top();
            s.pop();
            int result = Operation(a[i],(int)op1,(int)op2);
            s.push(result);
        }
        else if(isNumber(a[i]))
        {
            int operand=0;
            while(i<n && isNumber(a[i]))
            {
                operand=((operand*10) + ((a[i]-'0')));
                i++;
            }
            i--;
            s.push(operand);
        }
    }
    return (int)s.top();
}

int main()
{
    char a[]={"2,5+"};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"Value is : "<<postfixEvaluation(a,n-1);
    return 0;
}