#include<iostream>
#include<string.h>
using namespace std;
void isPalindrome(char *a) // or char a[]  (both are same)
{
	// Time : O(n)
    // Space : O(1)

	int l = 0;
	int h = strlen(a) - 1;
	while (l < h)
	{
		if (a[l++] != a[h--])
		{
			cout << "Not Palindrome" << endl;
			return;
		}
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