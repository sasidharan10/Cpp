#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal - using map and sorting based on freq.
    int minimumPushes(string word)
    {
        // TC: O(n) + O(mlogm) where m = 26.
        // SC: O(26)
        
        int n = word.length();
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++)
        {
            mp[word[i] - 'a']++;
        }
        sort(mp.begin(), mp.end(), greater<>());
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (mp[i] == 0)
                return cnt;
            if (i <= 7)
                cnt += mp[i];
            else if (i >= 8 && i <= 15)
                cnt += mp[i] * 2;
            else if (i >= 16 && i <= 23)
                cnt += mp[i] * 3;
            else
                cnt += mp[i] * 4;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    string str = "aabbccddeeffgghhiiiiii";
    cout << "Result: " << s.minimumPushes(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii

Youtube: https://www.youtube.com/watch?v=fX6sHghLCow

Code Link:

algorithm:

- Optimal Approach:

- We need to place the letters in the keypad, in such a way that, it requires minimum key strokes
  to type the word "word".
- We can place 8 letters, which can be types in 1 key stroke, then another 8 letters in 2 key strokes
  then another 8 letters in 3 key strokes and last 2 letters in 4 key strokes.
- So, we can place the letters with highest freq, in 1 key strokes, then 2 and so on, to find
  the minimum key strokes.
- First, we find frequency of every letter using a map.
- Sort the map based on frequency.
- The letters with high freq, will be having 1 key strokes and so on.
- We dont need to keep track of letters, along with their freq, since the problem is asking to
  just return the total key strokes.
- Hence, we calculate the key strokes based on the frequency and return the result.

*/

/*

3014. Minimum Number of Pushes to Type Word I

You are given a string word containing distinct lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which 
can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], 
we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can 
be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need 
to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, 
and 0 do not map to any letters.

Example 1:

Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.

Example 2:

Input: word = "xycdefghij"
Output: 12
Explanation: The remapped keypad given in the image provides the minimum cost.
"x" -> one push on key 2
"y" -> two pushes on key 2
"c" -> one push on key 3
"d" -> two pushes on key 3
"e" -> one push on key 4
"f" -> one push on key 5
"g" -> one push on key 6
"h" -> one push on key 7
"i" -> one push on key 8
"j" -> one push on key 9
Total cost is 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12.
It can be shown that no other mapping can provide a lower cost.
 
Constraints:

1 <= word.length <= 26
word consists of lowercase English letters.
All letters in word are distinct.

*/

/*
************* Java Code **************

    public static int minimumPushes(String word) {
        int n = word.length();
        int[] mp = new int[26];
        for (int i = 0; i < n; i++) {
            mp[word.charAt(i) - 'a']++;
        }
        mp = Arrays.stream(mp).boxed().sorted(Collections.reverseOrder()).mapToInt(Integer::intValue).toArray();
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (mp[i] == 0)
                return cnt;
            if (i <= 7)
                cnt += mp[i];
            else if (i >= 8 && i <= 15)
                cnt += mp[i] * 2;
            else if (i >= 16 && i <= 23)
                cnt += mp[i] * 3;
            else
                cnt += mp[i] * 4;
        }
        return cnt;
    }

*/