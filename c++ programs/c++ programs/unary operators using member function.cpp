#include <iostream>
using namespace std;

class Number {
    int x;

public:
    Number(int a) {
        x = a;
    }

    void operator++() {
        ++x;
    }

    void display() {
        cout << "Value = " << x;
    }
};

int main() {
    Number n(10);

    ++n;          // Calls operator++()
    n.display();

    return 0;
}

