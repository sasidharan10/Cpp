#include<iostream>
using namespace std;
void count(char *a ,int n)
{
    int count[255]={0};  //initialising all indices with 0
    int max=0;  //  maximum count of occurence of a variable
    char result;  // that varible having highest count
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;  // incrementing the corresponding ASCII index value
        if(max<count[a[i]])
        {
            max=count[a[i]];
            result=a[i];
        }
    }
    cout<<"Highest occured character is : '"<<result<<"' and its occurence is : "<<max;
}
int main()
{
    char a[]="sadi jdv djvkdv dvooaldo kfvokk";
    int n=sizeof(a)/sizeof(a[0]);
    count(a,n);
    return 0;
}
/*
- here we follow the hash technique where the ASCII code of each variable is denoted by the 
  indices of the array count[255]. whenever we read a characterfrom a given array, we increment 
  the corredponding value pointing to the indexhaving value of that ASCII code.
- max value is noting the maximum count of a variable and result will be getting updated whenever
  a new max value is found.
*/
/*

Write a program in C to find maximum occurring character in a string.

Test Data :
Input the string : Welcome to w3resource.com.

Expected Output :

The Highest frequency of character 'e' 
appears number of times : 4 

*/