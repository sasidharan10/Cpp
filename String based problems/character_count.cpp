#include<iostream>
#include<string>
#include<string.h>
#include<ctype.h>
using namespace std;
void char_count(char *a)
{
    int i=0,al=0,c=0,d=0;
    while(a[i]!='\0')
    {
        if(a[i]>='A' && a[i]<='Z' || a[i]>='a' && a[i]<='z')   //   isalpha(a[i])
        {
            al++;
            i++;
        }
        else if(a[i]>='0' && a[i]<='9')   // if(isdigit(a))
        {
            d++;
            i++;
        }
        else
        {
            c++;
            i++;
        }
    }
    cout<<"\nAlphabet : "<<al<<"\nNumbers : "<<d<<"\nCharacters : "<<c;
}
int main()
{
    char a[50]="GooD is go5od 98 *&$";
    cout<<"Enter a string : ";
    // fgets(a,sizeof(a),stdin);
    char_count(a);
}
// this is good4 like @