#include<iostream>
using namespace std;
int main()
{
    cout<<"Star box : "<<endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    cout<<"\nnumber box 1 : "<<endl;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"\nnumber box 2 : "<<endl;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<"\nnumber box reverse 1: "<<endl;
    for (int i = 5; i >= 1; i--)
    {
        for (int j = 5; j >= 1; j--)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"\nnumber box reverse 2: "<<endl;
    for (int i = 5; i >= 1; i--)
    {
        for (int j = 5; j >= 1; j--)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<"\nAlphabet box reverse 1: "<<endl;
    for (char i = 'E'; i >= 'A'; i--)
    {
        for (char j = 'E'; j >= 'A'; j--)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"\nnumber box reverse 2: "<<endl;
    for (int i = 65; i <=69; i++)
    {
        for (int j = 65; j <=69; j++)
        {
            cout<<(char)i<<" ";
        }
        cout<<endl;
    }
    return 0;
}