#include<stdio.h>
#include<string.h>
void swap(char *str1, char *str2)
{
	char temp[20];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	char str1[] = "geeks";
	char str2 [] = "forgeeks";
	swap(str1, str2);
	printf("str1 is %s, str2 is %s", str1, str2);
	getchar();
	return 0;
}