#include <iostream>
using namespace std;

class Address {
public:
    string city;

    Address() {
        city = "Kakinada";
    }
};

class Student {
public:
    string name;
    Address address;   // Object as class member

    Student() {
        name = "Vidhya";
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "City: " << address.city << endl;
    }
};

int main() {
    Student s;
    s.display();

    return 0;
}
