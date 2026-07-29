#include <iostream>
using namespace std;
class Outer
{
public:
    class Inner
    {
    public:
        void display()
        {
            cout << "This is the Inner Class." << endl;
        }
    };
    void show()
    {
        cout << "This is the Outer Class." << endl;
    }
};
int main()
{
    Outer obj1;
    Outer::Inner obj2;  
    obj1.show();
    obj2.display();
    return 0;
}
