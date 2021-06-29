#include<iostream>
using namespace std;
void vowels(string a[], int n)
{
	int vowels = 0,cons=0;
	string ch;
	char ch1;
	for (int i = 0; i < n; i++)
	{
		ch = a[i];
		for (int j = 0; ch[j] != '\0'; j++)
		{
			ch1 = ch[j];
			if (ch1 == 'a' || ch1 == 'A' || ch1 == 'e' || ch1 == 'E' || ch1 == 'i' ||
			        ch1 == 'I' || ch1 == 'o' || ch1 == 'O' || ch1 == 'u' || ch1 == 'U')
				vowels++;
			else if(ch1>='a' && ch1<='z' || ch1>='A' && ch1<='Z') 
				cons++;
			else
				continue;
		}
	}
	cout << "The no of vowels are : " << vowels << endl;
	cout << "The no of consonants are : " << cons << endl;
}
int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int count;
	string a[] = {"awesome", "fant65astic", "good", "fine"};
	int n = 4;
	vowels(a, n);
	return 0;
}