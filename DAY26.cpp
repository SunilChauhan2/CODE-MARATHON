/*Question 1: A university system needs to manage individuals who can be both students and employees. The system should allow for storing and retrieving details of such individuals efficiently.
The class structure is as follows:
1. Person (Base Class)
Stores common attributes: name (string) and age (integer).
Has a method display() to print the name and age.
2. Student (Derived from Person)
Inherits name and age.
Has an additional attribute studentID (integer).
Has a method show_student() to print the student ID.
3. Employee (Derived from Person)
Inherits name and age.
Has an additional attribute empID (integer).
Has a method show_employee() to print the employee ID.
4. WorkingStudent (Derived from Student and Employee)
Represents a person who is both a student and an employee.
Should be able to store name, age, studentID, and empID.
Should have a method show_details() that displays all the attributes correctly.
Requirements:
Implement the class hierarchy in C++ or Python.
Ensure that WorkingStudent can correctly access all attributes without ambiguity.
Provide a constructor for each class to initialize attributes.
Demonstrate the program with sample input and output.*/

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void display() {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
    }
};

class Student : virtual public Person { // Virtual inheritance
protected:
    int studentID;

public:
    Student(string n, int a, int sID) : Person(n, a), studentID(sID) {}

    void show_student() {
        cout << "Student ID: " << studentID << "\n";
    }
};

class Employee : virtual public Person { // Virtual inheritance
protected:
    int empID;

public:
    Employee(string n, int a, int eID) : Person(n, a), empID(eID) {}

    void show_employee() {
        cout << "Employee ID: " << empID << "\n";
    }
};

class WorkingStudent : public Student, public Employee {
public:
    WorkingStudent(string n, int a, int sID, int eID)
        : Person(n, a), Student(n, a, sID), Employee(n, a, eID) {}

    void showDetails() {
        display(); // Accessing Person's display method
        cout << "Student ID: " << studentID << "\n";
        cout << "Employee ID: " << empID << "\n";
    }
};

int main() {
    WorkingStudent ws("John Doe", 25, 12345, 67890);
    ws.showDetails();
    return 0;
}