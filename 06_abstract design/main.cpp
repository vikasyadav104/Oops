#include <iostream>
#include "bird.h"       // Contains Bird (abstract class) and sparrow
using namespace std;


/*
    birddoesSomething()

    Bird *&bird means:
    - bird is a pointer to Bird
    - & means reference to that pointer

    So the function receives the original Bird* pointer.
*/
void birddoesSomething(Bird *&bird)
{
    /*
        bird is a Bird* pointer,
        but it actually points to a sparrow object.

        Since eat() and fly() are virtual functions
        in Bird, runtime polymorphism happens.

        Therefore:
            bird->eat() -> sparrow::eat()
            bird->fly() -> sparrow::fly()
    */

    bird->eat();
    bird->fly();

    bird->eat();
    bird->fly();

    bird->eat();
    bird->fly();
}


int main()
{
    /*
        Bird* = type of pointer
        bird  = pointer variable
        new sparrow() = creates a Sparrow object

        So:

        Bird pointer
             |
             ↓
        Sparrow object

        This is possible because Sparrow inherits from Bird.
    */
    Bird *bird = new sparrow();


    /*
        Pass the Bird pointer to the function.

        Inside the function, because of virtual functions,
        Sparrow's eat() and fly() will be called.
    */
    birddoesSomething(bird);


    /*
        Program finished successfully.
    */
    return 0;
}