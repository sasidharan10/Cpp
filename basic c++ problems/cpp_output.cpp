#include <iostream>
#include <cstdio>    // for fgets()
#include <cstring>   // string.h in C lang
#include <string>    // to use string DS
using namespace std; // cin, cout, endl are members of std namespace
int main()
{
  int a;
  cout << "Enter number: ";
  cin >> a;
  cerr << "Number: " << a << endl;
  string b;
  cout << "Enter string b: ";
  cin.ignore();
  getline(cin, b);
  // getline(cin >> ws, b); // this fn is for string DS
  cout << "String b: " << b;
  char c[30];
  // cin>>c;                 // cin cannot take strings with spaces
  // gets(c);                // avoid it because it does not support buffer overflow()
  cout << "\nEnter string c: ";
  fgets(c, sizeof(c), stdin); // recommended
  cout << "Char array c: " << c;
  return 0;
}

/*
- cerr in C++ is un-buffered so it is used when one needs to display the error message immediately.
- getline() wont take input after "cin" since "cin" leaves the white spaces as garbage and when
- and when getline finds white space '\n' in buffer, the input stream is closed.
- we can use cin.ignore() or getline(cin>>ws,c) to clear that '\n' from the buffer.
- gets() doesnt work since it does not support overflow, use fgets instead.
*/