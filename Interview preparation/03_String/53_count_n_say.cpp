#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string countSay(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    string res = "11";
    int c = 0;
    for (int i = 3; i <= n; i++)
    {
        string temp = ""; // updating to null in every loop
        res = res + '$';  // delimiter to check in every loop
        c = 1;
        for (int j = 1; j < res.length(); j++)
        {
            if (res[j - 1] != res[j])
            {
                temp += to_string(c);
                temp += res[j - 1];
                c = 1;
            }
            else
                c++;
        }
        res = temp; // temp contains the newly updated string from start
    }
    return res;
}
int main()
{
    int n = 8;
    cout << "Count : " << countSay(n);
    return 0;
}

/*

1 - 1
2 - 11
3 - 21
4 - 1211
5 - 111221
6 - 312211
7 - 13112221
8 - 1113213211

- So here we have to print a string that contains first digit as count ofa number
  and second digit is the number itself.
- eg "3322251" has two 3's,three 2's,one 5,one 1 => 32231511
- 1,2 are base case,in 3 the first digit contains count of 1's in 2 (11), 
  and second digit is that number (1)

*/