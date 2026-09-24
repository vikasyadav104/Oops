#include <bits/stdc++.h>
using namespace std;


// ============================================================
//              CONST WITH CLASS / CONST FUNCTION
// ============================================================

class abc {
public:

    int x;
    int *y;
    int z;


    // --------------------------------------------------------
    // OLD STYLE CONSTRUCTOR
    // --------------------------------------------------------

    // abc(int _x, int _y, int _z = 0) {
    //     x = _x;
    //     y = new int(_y);
    //     z = _z;
    // }


    // --------------------------------------------------------
    // NEW STYLE CONSTRUCTOR
    // INITIALIZATION LIST
    // --------------------------------------------------------

    abc(int _x, int _y, int _z = 0)
        : x(_x), y(new int(_y)), z(_z)
    {}

    /*
        Initialization list directly initializes the members.

        x(_x)
            → x gets the value of _x

        y(new int(_y))
            → dynamically creates an int with value _y
            → y stores the address of that int

        z(_z)
            → z gets the value of _z


        Example:

            abc a(1, 2);

        Since _z has default value 0:

            x = 1
            *y = 2
            z = 0
    */


    /*
        YOUR COMMENT:

        the only difference between old ctor and new ctor is that
        when i initialize z a const then in old ctor it will give
        error and not initialize with any other value but
        in new ctor when i give int _z=0 then z accept that value


        IMPORTANT CLARIFICATION:

        The main difference is NOT simply because z is const.

        The important point is:

        A const data member MUST be initialized using
        an initialization list.

        Example:

            const int z;

        This will NOT work:

            abc(...) {
                z = 10;       // ❌
            }

        Because a const variable cannot be assigned after
        it has already been created.

        But this works:

            abc(...) : z(10) {}

        because z is initialized directly.
    */


    // --------------------------------------------------------
    // CONST MEMBER FUNCTION
    // --------------------------------------------------------

    int getx() const
    {
        return x;
    }

    /*
        The const after the function means:

            getx() cannot modify the object's data members.

        So inside getx():

            x = 10;       // ❌
            z = 20;       // ❌

        But reading is allowed:

            return x;     // ✅


        WHY DO WE NEED THIS?

        Because a const object can call only const member
        functions.

        Example:

            const abc a(1, 2);

            a.getx();     // ✅

        Therefore getx() must be const.
    */


    // --------------------------------------------------------
    // NON-CONST MEMBER FUNCTION
    // --------------------------------------------------------

    void setx(int _val)
    {
        x = _val;
    }

    /*
        setx() changes x.

        Therefore this function cannot be called on a const
        object.

            const abc a(1, 2);

            a.setx(10);       // ❌

        Because a const object cannot be modified.
    */


    // --------------------------------------------------------
    // CONST FUNCTION WITH POINTER DATA MEMBER
    // --------------------------------------------------------

    int gety() const
    {
        return *y;
    }

    /*
        y is a pointer.

            y
            ↓
        address of dynamically allocated int

        Example:

            y → [2]

        Therefore:

            y      = address
            *y     = value stored at that address

        gety() returns the value stored at that address.

        Since gety() is const, we cannot change the object
        through this function.

        So:

            *y = 10;       // ❌ inside this const function
    */


    // --------------------------------------------------------
    // NON-CONST FUNCTION
    // --------------------------------------------------------

    void sety(int _val)
    {
        *y = _val;
    }

    /*
        sety() changes the value pointed to by y.

        Example:

            *y = 2

        after:

            sety(10)

        becomes:

            *y = 10

        Therefore sety() is NOT const.
    */


    // --------------------------------------------------------
    // CONST FUNCTION
    // --------------------------------------------------------

    int getz() const
    {
        return z;
    }

    /*
        getz() only reads z.

        Therefore it can safely be a const function.
    */
};


// ============================================================
//                 CONST OBJECT AS PARAMETER
// ============================================================

void printABC(const abc &a)
{
    /*
        const abc &a means:

        - a is a reference to an abc object
        - const means we promise NOT to modify that object
        - & avoids making a copy of the entire object

        Therefore inside this function:

            a.x = 10;       // ❌
            a.setx(10);     // ❌
            a.sety(10);     // ❌

        But const functions can be called:

            a.getx();       // ✅
            a.gety();       // ✅
            a.getz();       // ✅
    */

    cout << a.getx() << " "
         << a.gety() << " "
         << a.getz() << endl;
}


// ============================================================
//                         MAIN
// ============================================================

int main()
{
    abc a(1, 2);

    /*
        Constructor receives:

            _x = 1
            _y = 2
            _z = 0    ← default value

        Therefore:

            a.x  = 1
            *a.y = 2
            a.z  = 0
    */

    printABC(a);

    // Output:
    // 1 2 0

    return 0;
}



// ============================================================
//              IMPORTANT: CONST VARIABLE
// ============================================================

/*
    const int x = 5;

    x is a constant integer.

    Initialization is allowed:

        const int x = 5;       // ✅

    But reassignment is NOT allowed:

        x = 10;                // ❌

    Once initialized, x cannot be changed.
*/


// ============================================================
//                    CONST WITH POINTER
// ============================================================


// ------------------------------------------------------------
// 1. CONST DATA, NON-CONST POINTER
// ------------------------------------------------------------

/*
    const int *a = new int(2);

    Same as:

        int y = 10;
        const int *a = &y;


    Here:

        a  → address
        *a → value


    IMPORTANT:

        const int *a

    means:

        "The value pointed to by a cannot be changed
         through a."

    But:

        "The pointer a itself CAN point somewhere else."
*/


/*
    int y = 10;

    const int *a = &y;

    cout << *a << endl;


    Here:

        y  = 10
        &y = address of y
        a  = address of y
        *a = 10


    Therefore:

        cout << *a;

    prints:

        10
*/


/*
    int b = 20;

    a = &b;

    cout << *a << endl;


    This is allowed.

    Why?

        a is NOT a const pointer.

    So a can change where it points.

    Before:

        a → y → 10

    After:

        a → b → 20


    Therefore:

        *a = 20
*/


// ❌ NOT ALLOWED:
//
// *a = 50;
//
// Because the data is const THROUGH a.
//
// a = &b;
//
// is allowed because the pointer itself is not const.



// ============================================================
//          2. CONST POINTER, BUT NON-CONST DATA
// ============================================================

/*
    int *const a = new int(2);

    Here:

        int *      → pointer to int
        const      → pointer itself is constant

    Therefore:

        *a = 20;       // ✅ allowed
        a = &b;        // ❌ not allowed


    In simple words:

        DATA can change
        POINTER cannot change
*/


/*
    int *const a = new int(2);

    cout << *a << endl;

    Output:

        2
*/


/*
    *a = 20;

    This changes the DATA.

        Before:

            a → 2

        After:

            a → 20

    This is allowed because the data is NOT const.
*/


/*
    cout << *a << endl;

    Output:

        20
*/


/*
    int b = 50;

    a = &b;       // ❌ ERROR


    Why?

    a is a CONST POINTER.

    Its address cannot be changed.

    So once:

        a → some address

    it must continue pointing to that same address.
*/


// ============================================================
//              3. CONST POINTER + CONST DATA
// ============================================================

/*
    const int *const a = new int(10);

    There are TWO const:

        const int
            ↓
        data cannot change

        *const a
            ↓
        pointer cannot change


    Therefore BOTH are locked.
*/


/*
    cout << *a << endl;

    Output:

        10
*/


/*
    *a = 50;

    ❌ NOT ALLOWED

    Why?

    Data is const.

    You cannot modify the value through a.
*/


/*
    int b = 100;

    a = &b;

    ❌ NOT ALLOWED

    Why?

    Pointer is also const.

    a cannot point to another address.
*/


// ============================================================
//                    QUICK REVISION
// ============================================================

/*

    1. const int *a

       CONST DATA
       NON-CONST POINTER

       *a = 20;     ❌
       a = &b;      ✅


    2. int *const a

       NON-CONST DATA
       CONST POINTER

       *a = 20;     ✅
       a = &b;      ❌


    3. const int *const a

       CONST DATA
       CONST POINTER

       *a = 20;     ❌
       a = &b;      ❌


    REMEMBER:

        a
        ↓
        address stored in pointer


        *a
        ↓
        value at that address


        &b
        ↓
        address of b
*/