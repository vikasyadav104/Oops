#include <bits/stdc++.h>
using namespace std;

class Student
{
    public:
    //Attributes
    int id;
    int age;
    string name;
    int nos; 

    //Constructor (ctor) : Default CConstructor
   Student(){
    cout<< "Default constructor is called"<<endl;
    }

   //Parameterized Constructor
    Student(int id, int age, string name, int nos)
     {
        cout<< "Parameterized constructor is called"<<endl;
          this->id = id;
          this->age = age;
          this->name = name;
          this->nos = nos;
     }

     //Copy Constructor
     Student(const Student &s) 
     {
        cout<< "Copy constructor is called"<<endl;
         this->id = s.id;
         this->age = s.age;
         this->name = s.name;
         this->nos = s.nos;
     }


    //behavior/ methods / functions
    void study()
    {
        cout<< this->name<< "Student is studying"<<endl;
    }
    // this pointer is used to access the currrent object of the class. It is used to access the attributes and methods of the current object.  

    void sleep()
    {
        cout<<"Student is sleeping"<<endl;
    }
    void bunk(){
        cout<< "Student is bunking"<<endl;
    }

    //destructor
    ~Student()
        {
            cout<<this->name<<" "<<"Destructor is called"<<endl;
        }

};


int main()
{
//   Student A;  //As soon Student A id made then it will call constructor and it will print the message "Default constructor is called"
//   A.id = 1;
//   A.age = 15;
//   A.name="Ranu";
//   A.nos = 10;
// //   return 0; // As soon Student A goes out of scope then it will call destructor and it will print the message "Destructor is called"
//    A.sleep();

//  Student B; // again constructor call for student B
//  B.id= 2;
//  B.age= 22;
//  B.name="Vikas";
//  B.nos= 15; 

//  B.bunk();  //This will call bunk function 
//  return 0; //now after this two time destructor will call for student A and B and it will print the message "Destructor is called" two times

//  Student A(3, 20, "Ravi", 12); //Parameterized constructor is called
//  //when we create an object it will create in stack memory
//  Student B(4, 25, "Vikas", 15); //Parameterized constructor is called
//  Student C(5, 30, "Ramesh", 20); //Parameterized constructor is called
  
//  cout<<A.id<<" "<<A.age<<" "<<A.name<<" "<<A.nos<<endl;
//  cout<<B.id<<" "<<B.age<<" "<<B.name<<" "<<B.nos<<endl;

   //Copy constructor

//    Student c= A;
//    cout<<c.id<<" "<<c.age<<" "<<c.name<<" "<<c.nos<<endl;
//    return 0;

//Dynamic allocation or Student pounter

Student *A= new Student(3, 20, "Ravi", 12); //Parameterized constructor is called
cout<<A->id<<" "<<A->age<<" "<<A->name<<" "<<A->nos<<endl;
A->study();

delete A; //Destructor is called for the object A
return 0; //but here then is no destructor call because we have created the object in heap memory so we have to delete the object manually
}