#include<iostream>
#include<stdio.h>
using namespace std;
void get(int*a)
{
	cout<<"\na[0] : "<<a[0]<<endl;
}
int main()
{

	// cout << "Hello World\n";
	// cout << sizeof(long)<<endl;
	// cout<<sizeof(const char*)<<endl;
	char a[10];
	int b[]={1,2,3,4,5,6};
	cout<<"Enter a name : "<<endl;
	// gets(a);   // avoid it because it does not support buffer overflow()
	fgets(a,sizeof(a),stdin);  // recommended
	cout<<"Name is : "<<a<<endl;
	get(b+2);
	return 0;
}