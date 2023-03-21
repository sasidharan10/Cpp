#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void swap1(char **s1, char **s2)
{ // for char pointer, we can swap the address
	char **temp;
	*temp = *s1;
	*s1 = *s2;
	*s2 = *temp;
}
void swap2(char *str1, char *str2)
{
	// for char array, only this method is available
	// and it causes undefined behaviour.
	char *temp = new char[20]; // dynamic array
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}
int main()
{
	char str1[] = "geeks"; //   char array
	char str2[] = "forgeeks";

	char *str3 = str1; // pointer, pointing to char array
	char *str4 = str2;

	swap1(&str3, &str4);
	printf("str3: %s\nstr4: %s", str3, str4);

	swap2(str1, str2);
	printf("\n\nstr1: %s\nstr2: %s", str1, str2);

	// these command s not working
	// cout << "sizeof(str1): " << sizeof(str1) << endl;
	// cout << "sizeof(str2): " << sizeof(str2) << endl;
	// cout << "strlen(str1): " << strlen(str1) << endl;
	// cout << "strlen(str2): " << strlen(str3) << endl;
	return 0;
}