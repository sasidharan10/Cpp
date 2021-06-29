#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream rd("sample.txt");
    string a;
    int i=0;
    getline(rd,a);
    while(a[i]!='\0')
    {
        if(a[i]==' ')
        {
            i++;
            continue;
            // cout<<endl;  for printing word by word in a line
        }
        else
            cout<<a[i];
        i++;
    }
    return 0;
}

// 29) Remove the spaces between two words of its content