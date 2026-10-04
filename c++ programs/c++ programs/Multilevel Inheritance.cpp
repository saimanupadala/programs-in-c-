#include <iostream>
using namespace std;

class Grandfather
{
public:
    void showA()
    {
        cout << "Grandfather" << endl;
    }
};

class Father : public Grandfather
{
public:
    void showB()
    {
        cout << "Father" << endl;
    }
};

class Son : public Father
{
public:
    void showC()
    {
        cout << "Son" << endl;
    }
};

int main()
{
    Son s;
    s.showA();
    s.showB();
    s.showC();

    return 0;
}
