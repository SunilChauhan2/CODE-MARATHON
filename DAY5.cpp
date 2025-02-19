// Question 1:Write a program to generate and print all the primes in the first n positive integers. 
// Input
// Each test case will contains a single integer n where n >=2.
// Output
// For each input case, generate and print all the primes in the first n positive integers.
// Sample Input
// 10
// Sample Output
// 2
// 3
// 5
// 7

#include<iostream>
using namespace std;
bool isprime(int n){
    int count=1;
    for(int i=1;i*i<=n; i++){
        if(n%i==0)
            count++;
    }
    return count==2;
}

// Question 2:Complete the below functions which will receive 3 integer pointers and print the sum of them.
// Note: Complete the given functions only, rest of the code is already written by the compiler for you.
// Input Format
// First line contains three integers.
// Output Format
// Print the sum of these 3 numbers.
// Sample Input
// 10 20 30
// Sample Output
// 60

int main()
{
    
    int n;
    cin>>n;
    for(int i=2 ; i<=n; i++){
        if(isprime(i)){
            cout<< i <<endl;
        }
    }
    
    return 0;
}
