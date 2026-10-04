#include <iostream>
using namespace std;
class Student
{
    int roll;
    string name;
public:
    Student()
    {
        roll = 0;
        name = "Unknown";
    }
    Student(int r, string n)
    {
        roll = r;
        name = n;
    }
    void display()
    {
        cout << "Roll Number: " << roll << endl;
        cout << "Name: " << name << endl;
    }
};
int main()
{
    Student s1;
    Student s2(101, "Vidhya");
    cout << "Student 1:" << endl;
    s1.display();
    cout << "\nStudent 2:" << endl;
    s2.display();
    return 0;
}
