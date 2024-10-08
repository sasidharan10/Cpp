#include <bits/stdc++.h>
using namespace std;
int main()
{
    string sentence = "This is a sample sentence";
    stringstream ss(sentence);
    string word;
    vector<string> words;

    // Split the sentence into words
    while (ss >> word)
    {
        words.push_back(word);
    }

    // Print the words
    for (const string &w : words)
    {
        cout << w << endl;
    }

    cout << "\nSplitting words with ',' delimiter: " << endl;
    string data = "apple,banana,orange,mango";
    stringstream ss2(data);
    string token;
    vector<string> tokens;

    // Split the string by comma ','
    while (getline(ss2, token, ','))
    {
        tokens.push_back(token);
    }

    // Print the tokens
    for (const string &t : tokens)
    {
        cout << t << endl;
    }

    return 0;
}