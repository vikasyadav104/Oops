#include <iostream>
#include "bird.h"
using namespace std;


/*
    ABSTRACT CLASS

    Bird contains pure virtual functions.
    Therefore Bird is an abstract class.

    Bird tells:
        "Every child must have eat() and fly()."
*/

class Bird {
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
};


/*
    CHILD CLASS

    Sparrow inherits Bird.

    Sparrow MUST implement:
        eat()
        fly()

    Now Sparrow is a concrete class.
*/

class Sparrow : public Bird {
public:

    void eat() override {
        cout << "Sparrow is eating\n";
    }

    void fly() override {
        cout << "Sparrow is flying\n";
    }
};


/*
    FUNCTION

    Bird*& means:
        reference to a Bird pointer

    The function can work with ANY object
    that inherits from Bird.
*/

void birddoesSomething(Bird *&bird)
{
    /*
        bird is a Bird pointer,
        but it actually points to a Sparrow object.

        Because eat() and fly() are virtual,
        Sparrow's functions are called.
    */

    bird->eat();   // Sparrow::eat()
    bird->fly();   // Sparrow::fly()

    bird->eat();   // Sparrow::eat()
    bird->fly();   // Sparrow::fly()

    bird->eat();   // Sparrow::eat()
    bird->fly();   // Sparrow::fly()
}


int main()
{
    /*
        Actual object = Sparrow
        Pointer type   = Bird*

        This is possible because:

            Sparrow IS-A Bird
    */

    Bird *bird = new Sparrow();

    /*
        Pass Bird pointer to function.
    */

    birddoesSomething(bird);

    return 0;
}