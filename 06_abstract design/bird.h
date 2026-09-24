/*
========================================================
                ABSTRACTION
========================================================

In your code:

    class Bird

is an ABSTRACT CLASS because it contains
PURE VIRTUAL FUNCTIONS.
*/


class Bird {

public:

    // Pure virtual functions
    virtual void eat() = 0;
    virtual void fly() = 0;

};


/*
========================================================
What does this mean?

    virtual void eat() = 0;

means:

    "Bird says that every child class MUST
     have an eat() function."

Similarly:

    virtual void fly() = 0;

means:

    "Every child class MUST have a fly() function."

Bird only defines WHAT functions are required.

It does not provide their implementation.
*/


/*
========================================================
Because Bird has pure virtual functions:

    Bird b;        // ❌ NOT ALLOWED

Bird is an ABSTRACT CLASS.
*/


/*
========================================================
CHILD CLASS
========================================================
*/

class Sparrow : public Bird {

public:

    // Sparrow MUST implement eat()
    void eat() override {
        cout << "Sparrow is eating\n";
    }

    // Sparrow MUST implement fly()
    void fly() override {
        cout << "Sparrow is flying\n";
    }

};


/*
========================================================
Why does Sparrow need both functions?

Because Bird said:

    virtual void eat() = 0;
    virtual void fly() = 0;

So Bird is basically giving Sparrow a CONTRACT:

    "You must provide:

        eat()
        fly()
    "
*/


/*
========================================================
If Sparrow doesn't implement one:

    class Sparrow : public Bird {

    public:

        void eat() override {
        }

        // fly() missing
    };


Then Sparrow ALSO becomes an ABSTRACT CLASS.

Therefore:

    Sparrow s;      // ❌ NOT ALLOWED
*/


/*
========================================================
If Sparrow implements BOTH:

    eat()
    fly()

then Sparrow becomes a normal/concrete class.

Therefore:

    Sparrow s;      // ✅ ALLOWED
*/


/*
========================================================
MAIN IDEA OF YOUR CODE
========================================================

                Bird
                 |
        ----------------
        |
     Sparrow

Bird says:

    eat()  → required
    fly()  → required

Sparrow says:

    eat()  → "Here is how I eat"
    fly()  → "Here is how I fly"


Therefore:

    Bird = WHAT is required

    Sparrow = HOW it is implemented


This is ABSTRACTION.
========================================================
*/