#include <iostream>
using namespace std;

class Student {
private:
    int marks;

protected:
    int rollNo;

public:
    string name;

    void setData() {
        marks = 90;
        rollNo = 101;
        name = "Vidhya";
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s;

    s.setData();
    s.display();

    // s.marks = 90;    // Error: private
    // s.rollNo = 101;  // Error: protected
    s.name = "Ravi";    // Allowed: public

    return 0;
}
