#include <iostream>
#include <algorithm>
using namespace std;
void inverted_Pattern_Number()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1 - i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void pattern_0_1()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void rhombus()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int k = 1; k <= n; k++)
        {
            cout << "* ";
        }

        cout << endl;
    }
    cout << "-----------------" << endl;
}
void number_Pyramid()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << k << " ";
        }

        cout << endl;
    }
    cout << "-----------------" << endl;
}
void palindrome_Number_Pyramid()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int k = i; k >= 1; k--)
        {
            cout << k << " ";
        }
        for (int l = 2; l <= i; l++)
        {
            cout << l << " ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void diamond_Pattern()
{
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void zig_zag()
{
    int row = 3, col = 9;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if ((i + j) % 4 == 0 || i == 2 && j % 4 == 0)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}
void pattern()
{
    int n=5;
    for (int i = 1; i <= n; i++)
    {
        int s=n;
        for (int j = 1; j <= i; j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <= n-i+1; k++)
        {
            cout<<s--;
        }
        
        cout << endl;
    }
}
int main()
{
    inverted_Pattern_Number();
    pattern_0_1();
    rhombus();
    number_Pyramid();
    palindrome_Number_Pyramid();
    diamond_Pattern();
    zig_zag();
    pattern();
    return 0;
}
/*

pattern_0_1() :
we can use this condition also :
if (i % 2 != 0 && j % 2 != 0 || i % 2 == 0 && j % 2 == 0)

zig_zag():
we have to check the indices where we have to print the star and find the common condition among them

*/
