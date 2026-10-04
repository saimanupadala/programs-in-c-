#include <iostream>
using namespace std;

int main()
{
    int choice;

    cout << "Enter choice (1, 2 or 3): ";
    cin >> choice;

    try
    {
        if (choice == 1)
            throw 10;              // integer exception
        else if (choice == 2)
            throw 3.14;            // double exception
        else if (choice == 3)
            throw "Error occurred"; // string exception
        else
            cout << "No exception" << endl;
    }

    catch (int e)
    {
        cout << "Integer exception caught: " << e << endl;
    }

    catch (double e)
    {
        cout << "Double exception caught: " << e << endl;
    }

    catch (const char* e)
    {
        cout << "String exception caught: " << e << endl;
    }

    return 0;
}
