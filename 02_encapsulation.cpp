#include <bits/stdc++.h>
using namespace std;

/*
=============================================================
                        CLASS
=============================================================

A class is a blueprint/template used to create objects.

Example:

    Student s1;
    Student s2;

Here:
    Student -> class
    s1, s2  -> objects
*/


class Student
{

private:

    /*
    =========================================================
                    PRIVATE ATTRIBUTES
    =========================================================

    private members can NOT be directly accessed from main().

    Example:

        Student s1;
        s1.id = 10;       // ❌ ERROR
        s1.gpa = 3.5;     // ❌ ERROR

    They can be accessed through public methods such as
    getters and setters.
    */

    int id;
    int age;
    string name;
    int nos;

    /*
    gpa is a POINTER.

    float* means:

        gpa stores the ADDRESS of a float variable.

    We are using dynamic memory here to understand:
        new
        pointer
        delete
    */

    float* gpa;

    string gf;


public:

    /*
    =========================================================
                        SETTER
    =========================================================

    A setter is a public function used to CHANGE/SET the
    value of a private attribute.

    Example:

        s1.setGpa(3.8);

    This allows controlled access to the private variable.
    */

    void setGpa(float gpa)
    {
        /*
        this->gpa
            |
            └── member variable (pointer)

        gpa
            |
            └── function parameter

        *this->gpa means:
            value stored at the address pointed to by gpa
        */

        *this->gpa = gpa;
    }


    /*
    =========================================================
                        GETTER
    =========================================================

    A getter is a public function used to READ a private
    attribute.

    Example:

        cout << s1.getGpa();
    */

    float getGpa()
    {
        return *this->gpa;
    }


    /*
    =========================================================
                        OTHER GETTER
    =========================================================
    */

    int getAge()
    {
        return this->age;
    }


    /*
    =========================================================
                    DEFAULT CONSTRUCTOR
    =========================================================

    Constructor:

        - Same name as class
        - No return type
        - Automatically called when object is created

    Example:

        Student s1;

    calls:

        Student()
    */

    Student()
    {
        cout << "Default constructor is called" << endl;

        /*
        Since gpa is a pointer, we must allocate memory
        before using *gpa.

        Otherwise:

            *gpa = something;

        would be dangerous because gpa doesn't point to
        valid memory yet.
        */

        gpa = new float;
    }


    /*
    =========================================================
                PARAMETERIZED CONSTRUCTOR
    =========================================================

    Constructor with parameters.

    Example:

        Student s1(1, 20, "John", 5, 3.5, "Jane");

    */

    Student(int id, int age, string name, int nos,
            float gpa, string gf)
    {
        cout << "Parameterized constructor is called" << endl;

        /*
        this pointer
        ------------

        this points to the CURRENT OBJECT.

        For:

            Student s1(...);

        inside the constructor:

            this

        points to s1.

        Therefore:

            this->id = id;

        means:

            s1.id = id;
        */

        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;

        /*
        Allocate memory dynamically.

        new float(gpa)

        creates a float in HEAP memory and returns its address.

        Example:

            gpa = 3.5

        memory:

            [3.5]
              ↑
              |
            this->gpa
        */

        this->gpa = new float(gpa);

        this->gf = gf;
    }


    /*
    =========================================================
                    COPY CONSTRUCTOR
    =========================================================

    Used to create a new object by copying another object.

    Example:

        Student s2 = s1;

    */

    Student(const Student& s)
    {
        cout << "Copy constructor is called" << endl;

        this->id = s.id;
        this->age = s.age;
        this->name = s.name;
        this->nos = s.nos;
        this->gf = s.gf;

        /*
        IMPORTANT:

        gpa is a pointer.

        We should NOT simply do:

            this->gpa = s.gpa;

        because then both objects would point to the SAME
        memory location.

        Instead, create separate memory.
        */

        this->gpa = new float(*s.gpa);
    }


    /*
    =========================================================
                    MEMBER FUNCTIONS
    =========================================================

    These functions represent the behaviour of Student.
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


private:

    /*
    =========================================================
                    PRIVATE MEMBER FUNCTION
    =========================================================

    This function can only be called from inside the class.

    main() cannot directly call:

        s1.gfchatting();

    because it is private.
    */

    void gfchatting()
    {
        cout << "Student is chatting with girlfriend" << endl;
    }


public:

    /*
    =========================================================
                        DESTRUCTOR
    =========================================================

    Destructor:

        ~Student()

    It is automatically called when an object is destroyed.

    Because we used:

        new float(...)

    we MUST release that memory using:

        delete gpa;

    Otherwise we can create a memory leak.
    */

    ~Student()
    {
        cout << this->name << " Destructor is called" << endl;

        delete gpa;
    }
};


/*
=============================================================
                        MAIN FUNCTION
=============================================================
*/

int main()
{

    /*
    =========================================================
                PARAMETERIZED CONSTRUCTOR
    =========================================================

    Creating object:

        s1

    This automatically calls the parameterized constructor.
    */

    Student s1(1, 20, "John", 5, 3.5, "Jane");


    /*
    =========================================================
                        ENCAPSULATION
    =========================================================

    We CANNOT do:

        cout << s1.gpa;       // ❌ private
        cout << s1.age;       // ❌ private
        cout << s1.gf;        // ❌ private

    Instead, we use PUBLIC getters.
    */


    /*
    GETTER

    Reads the private gpa.
    */

    cout << "GPA of student is: "
         << s1.getGpa()
         << endl;


    /*
    SETTER

    Changes the private gpa.
    */

    s1.setGpa(3.8);


    /*
    Check the updated value.
    */

    cout << "Updated GPA: "
         << s1.getGpa()
         << endl;


    /*
    GETTER for age
    */

    cout << "Age of student is: "
         << s1.getAge()
         << endl;


    /*
    MEMBER FUNCTIONS
    */

    s1.study();
    s1.sleep();
    s1.bunk();


    /*
    =========================================================
                    COPY CONSTRUCTOR
    =========================================================

    Creates another Student object using s1.

        s2

    */

    Student s2 = s1;

    cout << "Copied student's GPA: "
         << s2.getGpa()
         << endl;


    /*
    When main() ends:

        s2 destructor is called
        s1 destructor is called

    They automatically call:

        delete gpa;

    because these are normal local objects.
    */


    return 0;
}