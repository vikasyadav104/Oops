#include <bits/stdc++.h>
using namespace std;

//this is fucntion overloading example

// class Add{

//     public:

//     int sum(int a, int b){
//         return a+b;
//     }
//     int sum(int a, int b, int c){
//         return a+b+c;
//     }

//     double sum(double a, double b){
//         return a+b;
//     }

// };

// int main(){
//     int a=5;
//     int b=10;
//     int c=12;
//     Add add;

//     cout<<add.sum(a,b)<<endl;
//     cout<<add.sum(a,b,c)<<endl;

//     cout<<add.sum(5.5, 10.5)<<endl;

// }

//this is example of operator overloading

//Operator overloading is a type of polymorphism in C++ that allows you to redefine the behavior of operators for user-defined types (classes). It enables you to use operators like +, -, *, etc., with objects of your classes in a way that is intuitive and meaningful.

class Complex 
{
   public:
      int real;
      int imag;

      Complex()
      {
        real= imag =-1;

      }
    //   Complex(int r, int i): real(r), imag(i){}; //this is same as our old method of constructor but here we are using initializer list
      Complex(int r, int i){
        cout<<"Constructor called"<<endl;
        this->real= r;
        this->imag= i;
      }

      //syntax
      // ret_type operator symbol (const class_name &obj){
      //     //code}
      
    Complex operator + (const Complex &B){
        /// this-> A instance

        Complex temp;
        temp.real= this->real + B.real;
        temp.imag= this->imag + B.imag;
        return temp;
    }


      void print()
      {
        printf("%d + i%d\n", real, imag);
      }


};

int main(){
    Complex B(3, 2);
    Complex C(1, 7);
    B.print();

    // Complex C= B+C; //this will give error because we have not defined operator overloading for + operator
    //and here it is not know how to add two complex numbers
     


    //after operator overloading we can do this
  // we can also do many operator overloading like - , * , /,== etc. but we can not overload some operators like ::, sizeof, . , .* , ?: etc.
  //same as + operator 
    Complex D= B+C;   
    D.print();


}
