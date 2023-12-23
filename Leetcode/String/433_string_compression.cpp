#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int i = 0, index = 0;
        while (i < n)
        {
            int cnt = 0;
            char current_char = chars[i];
            while (i < n && current_char == chars[i])
            {
                i++;
                cnt++;
            }
            chars[index++] = current_char;
            if (cnt > 1)
            {
                string temp = to_string(cnt);
                for (char it : temp)
                {
                    chars[index++] = it;
                }
            }
        }
        return index;
    }
};
int main()
{
    Solution s;
    vector<char> chars{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    cout << "Array length after compression: " << s.compress(chars) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/string-compression

Youtube: https://www.youtube.com/watch?v=I7drewKcN1Y

algorithm:

- We have to compress the given array of char, by replacing it
  with characters, along with its count.
- Convert chars = ["a","a","b","b","c","c","c"] into ["a","2","b","2","c","3","c"]
  return the compressed array length, = "a2b2c3" = 6
- We use 2 pointers, "index" will we used to assign the characters and its
  count, while pointer "i"  will be used to count the current characters occurence.
- Once we found the current characters count, we just assign te character and its count.
- If count ==1, we just have to append the char, no need to append count.
- convert the count to string and loop through it(Edge case: count is of multiple digits).
- Here, we dont have to worry about the "index" pointer, overwritting the array, 
  as it will never go beyond the "i" pointer, hence we can use the same array.

*/

/*

443. String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead,
be stored in the input character array chars. Note that group lengths
that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.


Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

*/