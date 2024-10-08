#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // splitting words normally
    bool areSentencesSimilar3(string sentence1, string sentence2)
    {
        // TC: O(n + m)
        // SC: O(n + m)
        
        if (sentence2.length() > sentence1.length())
            swap(sentence1, sentence2);

        sentence1.push_back(' ');
        sentence2.push_back(' ');

        int m = sentence1.length();
        int n = sentence2.length();

        vector<string> vec1;
        vector<string> vec2;

        int start = 0;
        string temp;
        for (int i = 0; i < m; i++)
        {
            if (sentence1[i] == ' ')
            {
                temp = sentence1.substr(start, i - start);
                vec1.push_back(temp);
                start = i + 1;
            }
        }

        start = 0;
        for (int i = 0; i < n; i++)
        {
            if (sentence2[i] == ' ')
            {
                temp = sentence2.substr(start, i - start);
                vec2.push_back(temp);
                start = i + 1;
            }
        }

        int sz1 = vec1.size();
        int sz2 = vec2.size();

        int i = 0, j = sz1 - 1;
        int k = 0, l = sz2 - 1;
        while (i < sz1 && k < sz2 && vec1[i] == vec2[k])
        {
            i++;
            k++;
        }

        while (j >= 0 && l >= 0 && vec1[j] == vec2[l])
        {
            j--;
            l--;
        }

        if (l < k)
            return true;
        else
            return false;
    }

    // splitting words using stringstream
    bool areSentencesSimilar2(string sentence1, string sentence2)
    {
        // TC: O(n + m)
        // SC: O(n + m)

        if (sentence2.length() > sentence1.length())
            swap(sentence1, sentence2);

        int m = sentence1.length();
        int n = sentence2.length();

        vector<string> vec1;
        vector<string> vec2;

        stringstream ss1(sentence1);
        string word;
        while (getline(ss1, word, ' '))
        {
            vec1.push_back(word);
        }

        stringstream ss2(sentence2);
        while (getline(ss2, word, ' '))
        {
            vec2.push_back(word);
        }

        int sz1 = vec1.size();
        int sz2 = vec2.size();

        int i = 0, j = sz1 - 1;
        int k = 0, l = sz2 - 1;
        while (i < sz1 && k < sz2 && vec1[i] == vec2[k])
        {
            i++;
            k++;
        }

        while (j >= 0 && l >= 0 && vec1[j] == vec2[l])
        {
            j--;
            l--;
        }

        if (l < k)
            return true;
        else
            return false;
    }

    // using deque
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        // TC: O(n + m)
        // SC: O(n + m)

        // checking which sentence is bigger
        if (sentence2.length() > sentence1.length())
            swap(sentence1, sentence2);

        int m = sentence1.length();
        int n = sentence2.length();

        deque<string> dq1;
        deque<string> dq2;

        // splitting the sentence into words with the delimiter ' ' and storing into deque.
        stringstream ss1(sentence1);
        string word;
        while (getline(ss1, word, ' '))
        {
            dq1.push_back(word);
        }

        stringstream ss2(sentence2);
        while (getline(ss2, word, ' '))
        {
            dq2.push_back(word);
        }

        int sz1 = dq1.size();
        int sz2 = dq2.size();

        // poppong the common words from the front.
        while (!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front())
        {
            dq1.pop_front();
            dq2.pop_front();
        }

        // poppong the common words from the back.
        while (!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back())
        {
            dq1.pop_back();
            dq2.pop_back();
        }

        // if dq2 is empty, then we can say that, the remaining sentence in dq1 can be added
        // to dq2, to make both the sentence equal. 
        if (dq2.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    Solution s;
    string sentence1 = "My name is Haley", sentence2 = "My Haley";
    // string sentence1 = "of", sentence2 = "A lot of words";
    cout << "Result: " << s.areSentencesSimilar(sentence1, sentence2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/permutation-in-string

Youtube: https://www.youtube.com/watch?v=J9KwcuukMZE
 
Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Sentence%20Similarity%20III.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

1813. Sentence Similarity III

You are given two strings sentence1 and sentence2, each representing a sentence composed of
words. A sentence is a list of words that are separated by a single space with no leading or
trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary
sentence (possibly empty) inside one of these sentences such that the two sentences become
equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is"
between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a
sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are
similar. Otherwise, return false.

Example 1:
Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
Output: true

Explanation:
sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:
Input: sentence1 = "of", sentence2 = "A lot of words"
Output: false

Explanation:
No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:
Input: sentence1 = "Eating right now", sentence2 = "Eating"
Output: true

Explanation:
sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

Constraints:

1 <= sentence1.length, sentence2.length <= 100
sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
The words in sentence1 and sentence2 are separated by a single space.

*/

/*
************* Java Code **************

    // using 2 pointer
    public boolean areSentencesSimilar(String s1, String s2) {
        if (s1.length() < s2.length()) {
            String temp = s1;
            s1 = s2;
            s2 = temp;
        }

        List<String> vec1 = new ArrayList<>();
        List<String> vec2 = new ArrayList<>();

        // Splitting strings by spaces
        vec1 = Arrays.asList(s1.split(" "));
        vec2 = Arrays.asList(s2.split(" "));

        int i = 0, j = vec1.size() - 1; // s1 (vec1)
        int k = 0, l = vec2.size() - 1; // s2 (vec2)

        // Check for matching prefix
        while (k < vec2.size() && i < vec1.size() && vec2.get(k).equals(vec1.get(i))) {
            k++;
            i++;
        }

        // Check for matching suffix
        while (l >= k && vec2.get(l).equals(vec1.get(j))) {
            j--;
            l--;
        }

        return l < k;
    }

    public boolean areSentencesSimilar(String s1, String s2) {
        // Ensure s1 is the longer string
        if (s1.length() < s2.length()) {
            String temp = s1;
            s1 = s2;
            s2 = temp;
        }

        // Split the strings into Deques
        Deque<String> deq1 = new LinkedList<>(Arrays.asList(s1.split(" ")));
        Deque<String> deq2 = new LinkedList<>(Arrays.asList(s2.split(" ")));

        // Remove matching words from the front
        while (!deq1.isEmpty() && !deq2.isEmpty() && deq1.peekFirst().equals(deq2.peekFirst())) {
            deq1.pollFirst();
            deq2.pollFirst();
        }

        // Remove matching words from the back
        while (!deq1.isEmpty() && !deq2.isEmpty() && deq1.peekLast().equals(deq2.peekLast())) {
            deq1.pollLast();
            deq2.pollLast();
        }

        // If deq2 is empty, then s2 is a sub-sequence of s1
        return deq2.isEmpty();
    }

*/