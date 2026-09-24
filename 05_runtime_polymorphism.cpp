/*
===========================================================
              RUNTIME POLYMORPHISM IN C++
===========================================================

Polymorphism = One interface, many forms.

Runtime Polymorphism is achieved using:

    1. Inheritance
    2. Function overriding
    3. virtual function
    4. Base class pointer/reference

Main idea:

    Base* ptr = new Derived();
    ptr->function();

If function() is virtual in Base class,
then the function of the ACTUAL OBJECT is called.

===========================================================
*/


#include <bits/stdc++.h>
using namespace std;


/*
===========================================================
1. PARENT / BASE CLASS
===========================================================
*/

class shape {

public:

    // virtual is VERY IMPORTANT
    virtual void draw() {
        cout << "Shape is drawing" << endl;
    }

    // Virtual destructor
    virtual ~shape() {}
};


/*
===========================================================
2. CHILD / DERIVED CLASS
===========================================================
*/

class triangle : public shape {

public:

    // Function overriding
    void draw() override {
        cout << "Triangle is drawing" << endl;
    }
};


class Circle : public shape {

public:

    // Function overriding
    void draw() override {
        cout << "Circle is drawing" << endl;
    }
};


/*
===========================================================
3. FUNCTION USING BASE CLASS POINTER
===========================================================
*/

void ShapeDrawing(shape* s) {

    /*
        s is a pointer of type:

            shape*

        But s can point to:

            triangle
            Circle
            any class derived from shape
    */

    s->draw();
}


/*
===========================================================
4. MAIN
===========================================================
*/

int main() {


    /*
    -------------------------------------------------------
    CASE 1: Normal objects
    -------------------------------------------------------
    */

    Circle c;
    triangle t;


    /*
        &c = address of Circle object

        &t = address of triangle object
    */

    ShapeDrawing(&c);
    ShapeDrawing(&t);


    /*
    Output:

        Circle is drawing
        Triangle is drawing
    */


    /*
    =======================================================
    CASE 2: Base pointer -> Derived object
    =======================================================

    This is the MOST IMPORTANT PART.
    */

    shape* s1 = new Circle();

    shape* s2 = new triangle();


    /*
        s1:

            Pointer type  = shape*
            Object type   = Circle

        s2:

            Pointer type  = shape*
            Object type   = triangle
    */


    s1->draw();
    s2->draw();


    /*
    Output:

        Circle is drawing
        Triangle is drawing
    */


    /*
    -------------------------------------------------------
    Why?

        draw() is virtual in shape.

        Therefore C++ checks the ACTUAL OBJECT
        at runtime.

        s1 ---> Circle
                  |
                  ↓
             Circle::draw()


        s2 ---> triangle
                  |
                  ↓
             triangle::draw()
    */


    delete s1;
    delete s2;


    return 0;
}


/*
===========================================================
              VERY IMPORTANT CONCEPT
===========================================================

Consider:

    shape* s = new Circle();

Here:

    shape*       -> TYPE OF POINTER

    Circle       -> TYPE OF ACTUAL OBJECT


    s
    |
    |
    ↓
  Circle object


Now:

    s->draw();


Because draw() is virtual:

    shape* s
        |
        ↓
    actual object
        |
        ↓
      Circle
        |
        ↓
    Circle::draw()


Therefore:

    Circle is drawing


===========================================================
WITHOUT virtual
===========================================================

Suppose we write:

    class shape {

    public:

        void draw() {
            cout << "Shape is drawing";
        }
    };


And:

    class Circle : public shape {

    public:

        void draw() {
            cout << "Circle is drawing";
        }
    };


Now:

    shape* s = new Circle();

    s->draw();


Output:

    Shape is drawing


Why?

Because draw() is NOT virtual.

C++ uses the POINTER TYPE:

    shape*

So:

    shape* s
        |
        ↓
    shape::draw()


===========================================================
WITH virtual
===========================================================

    class shape {

    public:

        virtual void draw() {
            cout << "Shape is drawing";
        }
    };


Now:

    shape* s = new Circle();

    s->draw();


Output:

    Circle is drawing


Why?

Because draw() is virtual.

C++ checks the ACTUAL OBJECT:

    shape* s
        |
        ↓
    Circle object
        |
        ↓
    Circle::draw()


This is:

        RUNTIME POLYMORPHISM


===========================================================
&t VS m
===========================================================

Suppose:

    triangle t;

    triangle* p = &t;


Here:

    t  = actual object

    &t = address of object

    p  = pointer storing address of t


Now:

    triangle* m = new triangle();


Here:

    new triangle()
        |
        ↓
    creates triangle object
        |
        ↓
    returns its address
        |
        ↓
    m stores that address


Therefore both are pointers:

    triangle* p
    triangle* m


But:

    p points to an automatically created object.

    m points to a dynamically created object.


===========================================================
RUNTIME POLYMORPHISM FORMULA
===========================================================

Remember this:

    Base* ptr = new Derived();

    ptr->function();


AND:

    Base class function MUST be virtual.


So:

    Inheritance
          +
    Function Overriding
          +
    virtual function
          +
    Base pointer/reference
          |
          ↓
    Runtime Polymorphism


===========================================================
STATIC VS RUNTIME POLYMORPHISM
===========================================================

STATIC / COMPILE-TIME:

    Function Overloading
    Operator Overloading

Decision is made at compile time.


RUNTIME:

    Virtual Function
    Function Overriding
    Base Pointer / Reference

Decision is made at runtime.


===========================================================
MOST IMPORTANT INTERVIEW PATTERN
===========================================================

Whenever you see:

    Base* ptr = new Derived();

    ptr->function();


Immediately ask:

    Is function() virtual in Base?


YES
 ↓

Actual object's function is called.

Example:

    shape* s = new Circle();

    s->draw();

    ↓

    Circle::draw();


NO
 ↓

Base/pointer type determines the function.

Example:

    shape* s = new Circle();

    s->draw();

    ↓

    shape::draw();


===========================================================
ONE-LINE MEMORY TRICK
===========================================================

WITHOUT virtual:

    POINTER TYPE decides.


WITH virtual:

    ACTUAL OBJECT decides.


===========================================================
FINAL EXAMPLE
===========================================================

    shape* s = new Circle();

    s->draw();


Read it as:

    "Create a Circle object,
     but store its address in a shape pointer."

Then:

    "Call draw() using the shape pointer."

Because draw() is virtual:

    "Go and check the actual object."

Actual object = Circle

Therefore:

    Circle::draw()


===========================================================
                 RUNTIME POLYMORPHISM
===========================================================
*/