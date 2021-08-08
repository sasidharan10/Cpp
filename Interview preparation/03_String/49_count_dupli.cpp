#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
void countDuplicate1(char *str)
{
	// Time : O(n)
    // Space : O(n)

    int count[127]{0}; // initialise it to 0
    // all ascii codes are in between 0-127
    int i = 0;
    while (str[i] != '\0')
    {
        count[str[i]]++;
        i++;
    }
    // all characters corresponding ascii indices will have the count of their occurences
    i = 0;
    cout << "Count : " << endl;
    while (str[i] != '\0')
    {
        if (count[str[i]] > 1)
        {
            cout << str[i] << " : " << count[str[i]] << endl;
            count[str[i]] = 0;
        }
        i++;
    }
}
void countDuplicate2(char *str)
{
    // Time : O(n)
    // Space : O(n)

    unordered_map<char, int> m;
    int i = 0;
    while (str[i] != '\0')
    {
        m[str[i]]++;
        i++;
    }
    cout << "Count : " << endl;
    for (auto i : m)
    {
        if (i.second > 1)
            cout << i.first << " : " << i.second << endl;
    }
}
int main()
{
    char str[] = "test string";
    countDuplicate1(str);
    countDuplicate2(str);
    return 0;
}