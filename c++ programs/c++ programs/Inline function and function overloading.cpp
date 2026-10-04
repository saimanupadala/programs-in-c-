#include <iostream>
using namespace std;
inline int square(int n)
{
    return n * n;
}
int add(int a, int b)
{
    return a + b;
}
int add(int a, int b, int c)
{
    return a + b + c;
}
int main()
{
    cout << "Square of 5 = " << square(5) << endl;
    cout << "Sum of 2 numbers = " << add(10, 20) << endl;
    cout << "Sum of 3 numbers = " << add(10, 20, 30) << endl;
    return 0;
}
