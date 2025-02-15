// question 1:Write a program to show how to read and write integer values from user.
//  Input Format:
// Each test case contains 3 integers separated by space.
// Output Format:
// Print the 3 integers separated by space.
// Sample Input
// 10 20 30
// Sample Output
// 10 20 30
#include<iostream>
using namespace std;
int main()
{
    int n,m,l;
    cin>> n >> m >>l;
    cout<<" "<< n <<" "<< m <<" "<< l; 
    
   return 0;
}

//question 2:Input two numbers x and y from keyboard you need to print the sum of two numbers with 2 decimal digit.
// Sample input
// 10.2 13.89
// sample output
// 14.09
#include<iostream>
#include<iomanip>
using namespace std;
int main (){
    float x,y;
    cin>>x>>y;
    cout<<fixed<< setprecision(2) << x+y;
}
