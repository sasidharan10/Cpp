#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string printSequence(string str)
{
    string ref[] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6",
                    "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
    string output = "";

    int i = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            output += '0';
        else if (str[i] >= 97 && str[i] <= 122)
            output += ref[str[i] - 'a'];
        else if (str[i] >= 65 && str[i] <= 90)
            output += ref[str[i] - 'A'];
    }
    return output;
}
int main()
{
    string input = "GEEKSFORGEEKS";
    // string input = "geeksforgeeks";
    cout << "Sequence : " << printSequence(input) << endl;
    return 0;
}
