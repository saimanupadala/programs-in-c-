#include <iostream>
using namespace std;

void display(string name, int age = 18) {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

int main() {
    display("Vidhya");       // Uses default age
    display("Ravi", 20);     // Uses given age

    return 0;
}
