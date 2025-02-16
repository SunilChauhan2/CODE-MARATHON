/*Question 3: Write a program to swap the value of two variables without using a third variable.
Input Format:
Each test case will have 2 elements in two different lines between 0 - 9999.
Output Format:
For each input case, swap the input values of the variables.
Sample Input
10
20
Sample Output
20
10*/
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
     
    n = m+n;
    m = n-m;
    n =n-m;
    cout<<n<<endl;
    cout<<m<<endl;
return 0;
}

/*Question 4: Given three numbers, add them digit by digit and return the sum.
Complete the function addDigitByDigit() that accepts 3 integers and returns the sum , added digit by digit
Input
Input contains three numbers (0 - 1000), separated by a space.
Output
Return the sum of the 3 numbers
Sample Input
10 12 22
Sample Output
4*/
int addDigitByDigit(int a, int b, int c) {
  return a + b + c;
}


