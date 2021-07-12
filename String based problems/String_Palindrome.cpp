#include<iostream>
#include<string.h>
using namespace std;
void isPalindrome(char *a) // or char a[]  (both are same)
{
	int l = 0;
	int h = strlen(a) - 1;
	while (h > l)
	{
		if (a[l++] != a[h--])
		{
			cout << "Not Palindrome" << endl;
			return;
		}
		else
			continue;
	}
	cout << "It is Palindrome" << endl;
		return;
}
int main()
{
	char a[] = "abba";
	char b[] = "abbccbba";
	char c[] = "goinog";
	isPalindrome(a);
	isPalindrome(b);
	isPalindrome(c);
	return 0;
}