#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int isPlaindrome(string str,int start,int end)
{
    int i=start;
    int j=end;
    while (i<j)
    {
        if(str[i]!=str[j])
            return 0;
    }
    return end-start+1;
    
}
int longestPalindrome(string str)
{
    int count=0;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            
            
        }
    }
    return count;
}
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: " << longestPalindrome(str) << endl;
    return 0;
}