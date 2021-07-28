#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
void Reverse1(string str)
{
    int j=str.length()-1;
    for (int i = 0; i < str.length()/2; i++,j--)
    {
        swap(str[i],str[j]);
    }
    cout<<"String : "<<str<<endl;
}
void Reverse2(string str)
{
    cout<<"String : ";
    for (int i =str.length()-1; i >=0; i--)
    {
        cout<<str[i];
    }
    cout<<endl;
}
void Reverse3(string str)
{
    reverse(str.begin(),str.end());
    cout<<"String : "<<str<<endl;
}
void Reverse4(char *str)
{
    strrev(str);
    cout<<"String : "<<str;
}
int main()
{
    string str = "geeksforgeeks";
    Reverse1(str);
    Reverse2(str);
    Reverse3(str);
    char a[]="geeksforgeeks";
    Reverse4(a);
    return 0;
}