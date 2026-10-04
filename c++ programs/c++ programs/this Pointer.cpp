#include <iostream>
using namespace std;

class Student {
    int marks;

public:
    void setMarks(int marks) {
        this->marks = marks;
    }

    void display() {
        cout << "Marks = " << this->marks;
    }
};

int main() {
    Student s;

    s.setMarks(95);
    s.display();

    return 0;
}
