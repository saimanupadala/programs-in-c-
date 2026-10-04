#include <iostream>
using namespace std;

class Father
{
public:
    void father()
    {
        cout << "Father class" << endl;
    }
};

class Mother
{
public:
    void mother()
    {
        cout << "Mother class" << endl;
    }
};

class Child : public Father, public Mother
{
public:
    void child()
    {
        cout << "Child class" << endl;
    }
};

int main()
{
    Child c;
    c.father();
    c.mother();
    c.child();

    return 0;
}
