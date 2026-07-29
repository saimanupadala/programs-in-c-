#include <iostream>
using namespace std;
class Number
{
private:
    int num;
public:
    void getData()
    {
        cout << "Enter a number: ";
        cin >> num;
    }
    Number add(Number n)
    {
        Number temp;
        temp.num = num + n.num;
        return temp;      
    }
    void display()
    {
        cout << "Result = " << num << endl;
    }
};
int main()
{
    Number n1, n2, n3;
    cout << "Enter first number:\n";
    n1.getData();
    cout << "Enter second number:\n";
    n2.getData();
    n3 = n1.add(n2);      
    cout << "\nSum of two numbers:\n";
    n3.display();
    return 0;
}
