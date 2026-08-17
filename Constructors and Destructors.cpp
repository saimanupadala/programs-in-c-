#include <iostream>
using namespace std;
class Student
{
public:
    Student()
    {
        cout << "Constructor is called." << endl;
    }
    ~Student()
    {
        cout << "Destructor is called." << endl;
    }
};
int main()
{
    Student s;

    cout << "Inside main function." << endl;
    return 0;
}
