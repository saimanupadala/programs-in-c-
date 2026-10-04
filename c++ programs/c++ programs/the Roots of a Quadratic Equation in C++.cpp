#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c;
    float d, root1, root2;

    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;

    d = b * b - 4 * a * c;

    if (d > 0) {
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);

        cout << "Two real and distinct roots" << endl;
        cout << "Root 1 = " << root1 << endl;
        cout << "Root 2 = " << root2 << endl;
    }
    else if (d == 0) {
        root1 = -b / (2 * a);

        cout << "Two equal roots" << endl;
        cout << "Root = " << root1 << endl;
    }
    else {
        cout << "Roots are complex" << endl;
    }

    return 0;
}
