#include <iostream>
using namespace std;

class Student {
public:
    int marks;

    void display() {
        cout << "Marks = " << marks;
    }
};

int main() {
    Student s;

    s.marks = 90;

    Student *ptr = &s;

    ptr->display();

    return 0;
}
