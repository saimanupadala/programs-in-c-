#include <iostream>
using namespace std;
class Number
{
private:
    int a;
public:
    void getData()
    {
        cout << "Enter a number: ";
        cin >> a;
    }
    friend void display(Number n);
};
void display(Number n)
{
    cout << "The number is: " << n.a << endl;
}
int main()
{
    Number n;
    n.getData();
    display(n);
    return 0;
}
