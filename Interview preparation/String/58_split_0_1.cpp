#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int subStrCount(string str)
{
    int count=0;
    int i=0,j=0;
    for (int k = 0; k < str.length(); k++)
    {
        if(str[k]=='0')
            i++;
        else
            j++;
        if(i==j)
            count++;
    }
    if(count==0)
        return -1;
    
        return count;
    
}
int main()
{
    string str = "011110001";
    cout<<"Count : "<<subStrCount(str)<<endl;
    return 0;
}