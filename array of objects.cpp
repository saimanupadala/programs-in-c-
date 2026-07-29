 #include <iostream>
using namespace std;
class Student
{
public:
    int rollNo;
    string name;
    float marks;
    void getData()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }
    void displayData()
    {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }
};
int main()
{
    Student s[3];  
    cout << "Enter details of 3 students:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nStudent " << i + 1 << ":\n";
        s[i].getData();
    }
    cout << "\n--- Student Details ---\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nStudent " << i + 1 << ":";
        s[i].displayData();
    }
    return 0;
}
