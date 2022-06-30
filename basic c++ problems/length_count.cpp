#include <iostream>
#include <cstring> // string.h used for char array
using namespace std;
int main()
{
	string a = "awesome";
	char b[] = "fantastic";
	cout << "Strrev: " << strrev(b) << endl;
	int count = 0;
	cout << "string a : length() : " << a.length() << endl;
	cout << "string a : size() : " << a.size() << endl;
	cout << "char b : strlen() : " << strlen(b) << endl;
	for (int i = 0; b[i] != '\0'; i++)
		count++;
	cout << "char b : for loop : " << count << endl;
	return 0;
}

// char Arrays always add a null character(\0) at the end of array