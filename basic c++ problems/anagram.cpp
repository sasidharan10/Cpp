#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool anagram(string a, string b)
{
	// time  : O(nlogn)
	// space : O(1)
	
	int str1, str2;
	str1 = a.length();
	str2 = b.length();
	if (str1 != str2)
		return false;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < str1; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
int main()
{
	string a, b;
	cout << "Enter the  strings : " << endl;
	cin>>a>>b;
	if (anagram(a, b))
		cout << "They are anagram words" << endl;
	else
		cout << "They are not anagram words" << endl;
	return 0;
}