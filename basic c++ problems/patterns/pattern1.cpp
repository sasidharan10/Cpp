#include <iostream>
#include <algorithm>
using namespace std;
void box()
{
    int row = 5, col = 5;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void rectangle()
{
    int row = 5, col = 5;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (i == 1 || i == row || j == 1 || j == col)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void inverted_Half_Pyramid()
{
    int row = 5, col = 5;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void half_Pyramid()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void half_Pyramid_Number()
{
    int n=5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<i<<" ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void floyd_Triangle()
{
    int n=5,count=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<count++<<" ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
void butterfly()
{
    int n=4;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2*n; j++)
        {
            if(j>2*n-i || j<=i)
                cout<<"*";
            else
                cout<<" ";
        }
        cout << endl;
    }
        for (int i = n; i >= 1; i--)
    {
        for (int j = 2*n; j >= 1; j--)
        {
            if(j>2*n-i || j<=i)
                cout<<"*";
            else
                cout<<" ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}
int main()
{
    box();
    rectangle();
    inverted_Half_Pyramid();
    half_Pyramid();
    half_Pyramid_Number();
    floyd_Triangle();
    butterfly();
    return 0;
}