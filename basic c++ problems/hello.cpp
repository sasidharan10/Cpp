#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{

	// cout << "Hello World\n";
	// cout << sizeof(long)<<endl;
	// cout<<sizeof(const char*)<<endl;
	char a[10];
	cout<<"Enter a name : "<<endl;
	// gets(a);   // avoid it because it does not support buffer overflow()
	fgets(a,sizeof(a),stdin);  // recommended
	cout<<"Name is : "<<a<<endl;
}