#include<stdio.h>
#include<string.h>
using namespace std;
void swap(char *str1, char *str2)
{
	// char temp[20];
	char *temp;
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

int main()
{
	char str1[] = "geeks";
	char str2 [] = "forgeeks";
	swap(str1, str2);
	printf("str1: %s\nstr2: %s",str1,str2);
	return 0;
}