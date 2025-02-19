// Question 1:Write a program to input gross amount of bill and calculate the net amount according to the below discounts:
// If amount < 1000, then discount is 0%
// If amount is from 1001 to 5000, then discount is 5%
// If amount is from 5001 to 10000, then discount is 10%
// If amount > 10000, then discount is 15%
// An additional discount of 2% if bill is greater than 30000.
// Input Format
// Each test case contains an integer denoting the gross amount.
// Output Format
// Print the net amount of bill up to 2 decimal points.
// Sample Input
// 2500
// Sample Output
// 2375.00


#include<iostream>
#include<iomanip>
using namespace std;
double DiscoutMeasure(double grossAmt,double netAmt,double discount,double addditionalDis){
    if (grossAmt < 1000){
        discount = 0;
    }else if(grossAmt <= 5000){
        discount = 5;
    }else if(grossAmt <= 10000){
        discount = 10;
    }else if (grossAmt > 10000){
        discount = 15;
    }
    double netDiscount = (discount / 100) * grossAmt;
    netAmt = grossAmt - netDiscount;
    if( netAmt > 30000){
        addditionalDis = 2;
    }
     double additionalDiscount = (addditionalDis / 100) * netAmt;
    double Netamt = netAmt - additionalDiscount;
    cout<<fixed<<setprecision(2)<<Netamt;
    return 0;
}

int main(){
    double grossAmt;
    cin>>grossAmt;
    double netAmt = 0, discount = 0, additionalDis = 0;
    DiscoutMeasure(grossAmt, netAmt, discount, additionalDis);
    return 0;
}


// Question 2: Write a program to create menu driven calculator that performs basic arithmetic operations (add, subtract, multiply and divide) using switch case. The calculator should input two numbers and an operator from user. It should perform operation according to the operator entered and must take input in given format.
// Input Format:
// <number 1> <operator> <number 2>
// Output Format
// Print the output of the expression given up to 2 decimal points.
// Sample Input
// 10 + 20
// Sample Output
// 30.00

#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int a , b;
    char op ;
    cin>>a>>op>>b;
    switch(op){
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            if (b != 0)
                cout << a / b << endl;
        default:
            cout << "Invalid operator" << endl;
        }
        return 0;
    }

