#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    printf("%x",-1<<4);
}

/*

-1 = 0000 0000 0000 0001

1s complement = 1111 1111 1111 1110
2s complement = 1111 1111 1111 1110
                                 +1
              = 1111 1111 1111 1111

now left shift 4 times = 1111 1111 1111 0000
                           f    f    f    0
                       = fff0 (16 bit)
                       = fffffff0 (32 bit)




*/