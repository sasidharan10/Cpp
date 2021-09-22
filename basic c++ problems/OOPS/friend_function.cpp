#include <iostream>
#include <algorithm>
using namespace std;
class Complex
{
    int a, b;
    friend Complex sumComplex(Complex o1, Complex o2);

public:
    void setNumber(int, int);
    void printNumber();
};
void Complex::setNumber(int n1, int n2)
{
    a = n1;
    b = n2;
}
void Complex::printNumber()
{
    cout << "Your number is " << a << " + " << b << "i" << endl;
}
Complex sumComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
int main()
{
    Complex c1, c2, c3;
    c1.setNumber(4, 1);
    c1.printNumber();
    c2.setNumber(5, 2);
    c2.printNumber();
    c3 = sumComplex(c1, c2);
    cout << "Sum is : " << endl;
    c3.printNumber();
    return 0;
}

/* Properties of friend functions

1. Not in the scope of class  (no need to use '::')
2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contains the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name to access any member.

*/