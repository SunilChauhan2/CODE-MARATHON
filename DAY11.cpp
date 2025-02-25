// Question 1: Write a program that accepts an integer n (where n >=2) and print all the prime factors of n using recursion.
// Sample Input
// 24
// Sample Output
// 2
// 2
// 2
// 3
// Constraints : Do not declare any global variables. Do not use any loops; you must use recursion. You can declare as many primitive variables like ints as you like. You are allowed to define other "helper" functions if you like; they are subject to these same constraints.

#include <iostream>
using namespace std;
void printPrimeFactors(int n, int divisor = 2) {
    
    if (n == 1) {
        return;
    }

    
    if (n % divisor == 0) {
        std::cout << divisor << std::endl; 
        printPrimeFactors(n / divisor, divisor); 
    } else {
        
        printPrimeFactors(n, divisor + 1);
    }
}

int main() {
    int n;
   
    std::cin >> n;

    if (n < 2) {
        std::cout << "Please enter an integer greater than or equal to 2." << std::endl;
        return 1; 
    }

    
    printPrimeFactors(n); 

    return 0;
}