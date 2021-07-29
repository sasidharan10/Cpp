#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream rd("sample.txt");
    string a;
    int i = 0;
    getline(rd, a);
    while (a[i] != '\0')
    {
        if (a[i] == ' ')
        {
            i++;
            continue;
            // cout<<endl;  for printing word by word in a line
        }
        else
            cout << a[i];
        i++;
    }
    return 0;
}

/*

Write a program in C to read a file and remove the spaces between two words of its content.

Expected Output :

The content of the file is :                                           
The quick brown fox jumps over the lazy dog                            
After removing the spaces the content is :                             
Thequickbrownfoxjumpsoverthelazydog

*/