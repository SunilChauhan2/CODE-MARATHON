/*Question 1: Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay 50 Rupees toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of the total amount of money collected.
Model this tollbooth with a class called TollBooth. The two data items are to hold the total number of cars, and to hold the total amount of money collected.
A constructor initializes both of these to 0.
A member function called payingCar() increments the car total and adds 50/- to the cash total.
Another function, called nopayCar(), increments the car total but adds nothing to the cash total.
Finally, a member function called display() displays the two totals.
Make appropriate member functions const.
The main function should allow the user to press 'p' to count a paying car, and 'n' to count a nonpaying car. Pushing the 'q' key should cause the program to print out the total cars and total cash and then exit.
Sample Input
p
p
p
n
p
n
p
q
Sample Output
Total Cash : 250/-
Total Cars : 7*/

#include<iostream>
#include<cstdio>
#include<cmath>
// Include headers as needed
using namespace std;

class TollBooth
{
  public:
    int a;
    int c;
    TollBooth()
    {
        a = 0;
        c = 0;
    }
    
    void payingCar()
    {
        a++;
        c += 50;
    }
    
    void nopayCar()
    {
        a++;
    }
    
    void display() const
    {
        cout << "Total Cash : " << c << "/-" << endl;
        cout << "Total Cars : " << a << endl;
    }
};

int main()
{
    TollBooth booth;
    char ch;
    
    while (true)
    {
        cin >> ch;
        if (ch == 'p')
            booth.payingCar();
        else if (ch == 'n')
            booth.nopayCar();
        else if (ch == 'q')
        {
            booth.display();
            break;
        }
    }
    
    // Return 0 to indicate normal termination
    return 0;
}


/*Question 2: Implements Complex numbers using classes in C++.
The program implements class Complex which gives facility to initialize Complex objects using constructors and add and subtract two Complex objects using + and - operators.
Also add one display() function to display the complex number as 12+4i format, where 12 is real part and 4 is imaginary part of it.*/

class Complex
{
  private:
   int real, imag;
  public:
  Complex() : real(0), imag(0) {}
   
   Complex(int r, int i) : real(r), imag(i) {}
   
   Complex operator+(const Complex& obj)
   {
       return Complex(real + obj.real, imag + obj.imag);
   }
   
   Complex operator-(const Complex& obj)
   {
       return Complex(real - obj.real, imag - obj.imag);
   }
   
   void display()
   {
       cout << real << "+" << imag << "i";
   }
};