#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
                    CLASS: Student
===========================================================

A class is a blueprint/template for creating objects.

Example:
    Student A;
    Student B;

Here A and B are objects of the Student class.
*/

class Student
{
public:

    /*
    =======================================================
                    DATA MEMBERS / ATTRIBUTES
    =======================================================
    */

    int id;
    int age;
    string name;
    int nos;       // number of subjects


    /*
    =======================================================
                    DEFAULT CONSTRUCTOR
    =======================================================

    A constructor:
    - has the same name as the class
    - has NO return type
    - is automatically called when an object is created

    Default constructor:
    - takes no arguments

    Example:
        Student A;

    This automatically calls:
        Student()
    */

    Student()
    {
        cout << "Default constructor is called" << endl;

        // We can also initialize values here
        id = 0;
        age = 0;
        name = "Unknown";
        nos = 0;
    }


    /*
    =======================================================
                PARAMETERIZED CONSTRUCTOR
    =======================================================

    A parameterized constructor takes arguments.

    Example:

        Student A(1, 20, "Vikas", 5);

    Here:
        id   = 1
        age  = 20
        name = "Vikas"
        nos  = 5
    */

    Student(int id, int age, string name, int nos)
    {
        cout << "Parameterized constructor is called" << endl;

        /*
        Why do we use "this->"?

        There are two variables called id:

            int id;          // class member
            int id           // constructor parameter

        this->id means:
            id belonging to the CURRENT OBJECT

        So:

            this->id = id;

        means:

            object's id = parameter id
        */

        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
    }


    /*
    =======================================================
                    COPY CONSTRUCTOR
    =======================================================

    A copy constructor creates a NEW object by copying
    an EXISTING object.

    Syntax:

        Student B = A;

    B will get the data of A.

    The parameter is generally:

        const Student &s

    &  -> reference (avoid creating another copy)
    const -> we don't want to modify s
    */

    Student(const Student &s)
    {
        cout << "Copy constructor is called" << endl;

        this->id = s.id;
        this->age = s.age;
        this->name = s.name;
        this->nos = s.nos;
    }


    /*
    =======================================================
                    MEMBER FUNCTIONS / METHODS
    =======================================================

    These functions describe the BEHAVIOUR of Student.
    */


    void study()
    {
        cout << this->name << " is studying" << endl;
    }


    void sleep()
    {
        cout << this->name << " is sleeping" << endl;
    }


    void bunk()
    {
        cout << this->name << " is bunking" << endl;
    }


    /*
    =======================================================
                        DESTRUCTOR
    =======================================================

    Destructor:
        ~Student()

    It is automatically called when an object is destroyed.

    Destructor:
    - has ~ before class name
    - has no return type
    - takes no parameters

    For a normal stack object:

        Student A;

    destructor is automatically called when A goes out
    of scope.

    For a dynamically allocated object:

        Student *A = new Student(...);

    we have to manually destroy it using:

        delete A;
    */

    ~Student()
    {
        cout << this->name << " Destructor is called" << endl;
    }
};


/*
===========================================================
                        MAIN FUNCTION
===========================================================
*/

int main()
{

    /*
    =======================================================
                    1. DEFAULT CONSTRUCTOR
    =======================================================

    Object is created in STACK memory.

        Student A;

    Default constructor is automatically called.
    */

    Student A;

    A.id = 1;
    A.age = 20;
    A.name = "Vikas";
    A.nos = 5;

    cout << A.id << " "
         << A.age << " "
         << A.name << " "
         << A.nos << endl;

    A.study();
    A.sleep();
    A.bunk();


    /*
    =======================================================
                2. PARAMETERIZED CONSTRUCTOR
    =======================================================

    Instead of creating an empty object and then assigning
    values, we can give values while creating the object.

        Student B(2, 21, "Ravi", 6);
    */

    Student B(2, 21, "Ravi", 6);

    cout << B.id << " "
         << B.age << " "
         << B.name << " "
         << B.nos << endl;

    B.study();


    /*
    =======================================================
                    3. COPY CONSTRUCTOR
    =======================================================

    Create C by copying B.

        Student C = B;

    This calls the COPY CONSTRUCTOR.

    C and B are TWO DIFFERENT OBJECTS.

    Initially, their data is the same.
    */

    Student C = B;

    cout << C.id << " "
         << C.age << " "
         << C.name << " "
         << C.nos << endl;


    /*
    =======================================================
                    4. THIS POINTER
    =======================================================

    Inside the class:

        this

    points to the CURRENT OBJECT.

    For example, when:

        B.study();

    is called, inside study():

        this

    points to B.

    Therefore:

        this->name

    means:

        B.name
    */


    /*
    =======================================================
                5. DYNAMIC MEMORY ALLOCATION
    =======================================================

    We can create an object in HEAP memory using new.

        Student *D = new Student(...);

    D is a POINTER.

    Because D is a pointer, we access members using:

        D->id
        D->name
        D->study()

    Instead of:

        D.id
        D.name
        D.study()
    */

    Student *D = new Student(3, 22, "Ramesh", 7);

    cout << D->id << " "
         << D->age << " "
         << D->name << " "
         << D->nos << endl;

    D->study();


    /*
    =======================================================
                        DELETE
    =======================================================

    D was created using:

        new

    Therefore we manually destroy it using:

        delete D;

    This calls the destructor of D.
    */

    delete D;


    /*
    =======================================================
                    END OF MAIN
    =======================================================

    A, B and C were normal local objects.

    They are automatically destroyed when main() ends.

    Therefore their destructors will automatically be called.

    D was dynamically allocated and was already destroyed
    using:

        delete D;
    */

    return 0;
}