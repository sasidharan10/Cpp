#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	int a, b, c, d, e, g, f, h, i,j,k;
	a = b = c = d = e = f = g = h = i = j=k=1;
	a = a++ + ++a;
	b = b++ + b++;
	c = ++c + ++c;
	d = ++d + d++;
	e = ++e + e++ + ++e;
	f = f++ + ++f + ++f;
	g = g++ + ++g + g++;
	cout << "1) a++ + ++a : " << a << endl;
	cout << "2) b++ + b++ : " << b << endl;
	cout << "3) ++c + ++c : " << c << endl;
	cout << "4) ++d + d++ : " << d << endl;
	cout << "5) ++e + e++ + ++e : " << e << endl;
	cout << "6) f++ + ++f + ++f : " << f << endl;
	cout << "7) g++ + ++g + g++ : " << g << endl;
	printf("8) ++i , i , i++ : %d, %d, %d \n", ++i, i, i++);
	printf("9) j++ , j , ++j : %d, %d, %d \n", j++, j, ++j);
	cout<<"10) ++k<<k<<k++ : "<<++k<<k<<k++;
	// for 8th and 9th statement, the evaluation is done from right to left and printing is done from left to right 
	return 0;
}