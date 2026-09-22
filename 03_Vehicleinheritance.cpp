#include <bits/stdc++.h>
using namespace std;


/*
===============================================================
                        INHERITANCE
===============================================================

Inheritance allows one class to acquire properties and
behaviour of another class.

Parent class / Base class
        |
        |
        ↓
     Vehicle
      /    \
     /      \
    ↓        ↓
   Car   MotorCycle


This is called:

            HIERARCHICAL INHERITANCE

Because:

    One parent
       |
       ├── Car
       |
       └── MotorCycle


Also:

    Vehicle → Car

is an example of SINGLE INHERITANCE.

    Vehicle → MotorCycle

is also an example of SINGLE INHERITANCE.
*/


/*
================================================================
                    PARENT / BASE CLASS
================================================================

Vehicle contains properties and behaviours common to different
vehicles.

Car and MotorCycle will inherit these properties and behaviours.
*/

class Vehicle
{

protected:

    /*
    ============================================================
                        PROTECTED
    ============================================================

    protected members:

        ❌ Cannot be directly accessed from main()

            Vehicle V;
            V.name;       // ERROR

        ✅ Can be accessed inside Vehicle

        ✅ Can be accessed inside derived classes

    This is why Car and MotorCycle can use 'name' directly.
    */

    string name;
    string model;
    int noOfTyres;


public:

    /*
    ============================================================
                        CONSTRUCTOR
    ============================================================
    */

    Vehicle(string _name, string _model, int _noOfTyres)
    {
        cout << "Vehicle constructor called" << endl;

        this->name = _name;
        this->model = _model;
        this->noOfTyres = _noOfTyres;
    }


    /*
    ============================================================
                    GETTER FOR NAME
    ============================================================

    Because name is protected, main() cannot directly access it.

    We provide a public function to access it.
    */

    string getName()
    {
        return this->name;
    }


    /*
    ============================================================
                    PARENT CLASS FUNCTION
    ============================================================
    */

    void startEngine()
    {
        cout << "Engine is starting: "
             << name << " " << model << endl;
    }


    void stopEngine()
    {
        cout << "Engine is stopping: "
             << name << " " << model << endl;
    }


    /*
    ============================================================
                        DESTRUCTOR
    ============================================================
    */

    ~Vehicle()
    {
        cout << "Vehicle destructor called" << endl;
    }
};


/*
================================================================
                    DERIVED / CHILD CLASS
================================================================

Syntax:

    class Car : public Vehicle

means:

    Car inherits from Vehicle.

Therefore:

    Car IS-A Vehicle

Car gets accessible members/functions of Vehicle.
*/


class Car : public Vehicle
{

private:

    /*
    These are properties specific to Car.
    */

    int noOfDoors;
    string transmissionType;


public:

    /*
    ============================================================
                    CAR CONSTRUCTOR
    ============================================================

    Notice:

        : Vehicle(...)

    This is the constructor initializer list.

    Before the Car constructor executes, the Vehicle constructor
    must execute because Vehicle is the parent class.
    */

    Car(string _name,
        string _model,
        int _noOfTyres,
        int _noOfDoors,
        string _transmissionType)

        : Vehicle(_name, _model, _noOfTyres)
    {
        cout << "Car constructor called" << endl;

        this->noOfDoors = _noOfDoors;
        this->transmissionType = _transmissionType;
    }


    /*
    ============================================================
                    CAR-SPECIFIC FUNCTION
    ============================================================
    */

    void startAC()
    {
        cout << "AC has started in "
             << getName() << endl;
    }


    /*
    ============================================================
                    CAR DESTRUCTOR
    ============================================================
    */

    ~Car()
    {
        cout << "Car destructor called" << endl;
    }
};


/*
================================================================
                    ANOTHER DERIVED CLASS
================================================================

MotorCycle also inherits from Vehicle.

So:

        Vehicle
           |
           ↓
      MotorCycle

This is also SINGLE INHERITANCE.

Because both Car and MotorCycle have the SAME parent Vehicle,
the overall relationship is:

            Vehicle
            /     \
           /       \
         Car    MotorCycle

This is HIERARCHICAL INHERITANCE.
*/


class MotorCycle : public Vehicle
{

private:

    string handleBarStyle;
    string suspensionType;


public:

    /*
    ============================================================
                MOTORCYCLE CONSTRUCTOR
    ============================================================
    */

    MotorCycle(string _name,
               string _model,
               int _noOfTyres,
               string _handleBarStyle,
               string _suspensionType)

        : Vehicle(_name, _model, _noOfTyres)
    {
        cout << "MotorCycle constructor called" << endl;

        this->handleBarStyle = _handleBarStyle;
        this->suspensionType = _suspensionType;
    }


    /*
    ============================================================
                    MOTORCYCLE FUNCTION
    ============================================================
    */

    void wheelie()
    {
        /*
        name is protected in Vehicle.

        Therefore MotorCycle can directly access it.
        */

        cout << "Wheelie is done by "
             << name << endl;
    }


    /*
    ============================================================
                    MOTORCYCLE DESTRUCTOR
    ============================================================
    */

    ~MotorCycle()
    {
        cout << "MotorCycle destructor called" << endl;
    }
};


/*
================================================================
                            MAIN
================================================================
*/

int main()
{

    /*
    ============================================================
                        CAR OBJECT
    ============================================================

    Creating:

        Car A(...)

    Because Car inherits Vehicle:

        Vehicle constructor
                ↓
        Car constructor

    will execute in this order.
    */

    Car A(
        "Maruti 800",
        "LXI",
        4,
        4,
        "Manual"
    );


    /*
    ============================================================
                    INHERITED FUNCTIONS
    ============================================================

    Car did NOT define startEngine().

    It inherited startEngine() from Vehicle.

    Therefore this works:

        A.startEngine();
    */

    A.startEngine();


    /*
    Car-specific function.
    */

    A.startAC();


    /*
    Another inherited function.
    */

    A.stopEngine();


    /*
    ============================================================
                    MOTORCYCLE OBJECT
    ============================================================
    */

    MotorCycle B(
        "KTM Duke",
        "200",
        2,
        "Clip-on",
        "Telescopic"
    );


    /*
    MotorCycle-specific function.
    */

    B.wheelie();


    /*
    MotorCycle can ALSO use Vehicle functions because it
    inherited them.
    */

    B.startEngine();
    B.stopEngine();


    /*
    ============================================================
                    DESTRUCTOR ORDER
    ============================================================

    When main() ends:

        First child destructor
                ↓
        Then parent destructor

    For B:

        MotorCycle destructor
                ↓
        Vehicle destructor

    For A:

        Car destructor
                ↓
        Vehicle destructor
    */


    return 0;
}