#include <iostream>
using namespace std;

class Animal
{
public:
    void eat()
    {
        cout << "Animal eats" << endl;
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:
    void meow()
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Dog d;
    d.eat();
    d.bark();

    Cat c;
    c.eat();
    c.meow();

    return 0;
}
