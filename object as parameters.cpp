   #include <iostream>
using namespace std;
class Student
{
private:
    int rollNo;
    float marks;
public:
    void getData()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Marks: ";
        cin >> marks;
    }
    void display()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
    void compare(Student s)
    {
        if (marks > s.marks)
            cout << "First student has higher marks." << endl;
        else if (marks < s.marks)
            cout << "Second student has higher marks." << endl;
        else
            cout << "Both students have equal marks." << endl;
    }
};
int main()
{
    Student s1, s2;
    cout << "Enter details of First Student:\n";
    s1.getData();
    cout << "\nEnter details of Second Student:\n";
    s2.getData();
    cout << "\nFirst Student Details:\n";
    s1.display();
    cout << "\nSecond Student Details:\n";
    s2.display();
    cout << "\nComparison Result:\n";
    s1.compare(s2);  
    return 0;
}
