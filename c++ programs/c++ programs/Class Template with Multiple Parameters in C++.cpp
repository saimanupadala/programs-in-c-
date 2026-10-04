#include <iostream>
using namespace std;

template <class T1, class T2>
class Student {
    T1 rollNo;
    T2 marks;

public:
    Student(T1 r, T2 m) {
        rollNo = r;
        marks = m;
    }

    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student<int, float> s1(101, 89.5);

    Student<int, int> s2(102, 95);

    cout << "Student 1:" << endl;
    s1.display();

    cout << "\nStudent 2:" << endl;
    s2.display();

    return 0;
}
