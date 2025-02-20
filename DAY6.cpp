// Question 1: Write a method threeConsecutive(int a,int b,int c) that accepts three integers as parameters and returns 1 if they are three consecutive numbers ( i.e if the numbers can be arranged into an order such that their values differ by exactly 1 ) otherwise return 0.
// For example, the call of ThreeConsecutive(3, 2, 4) would return 1.
// Input Format:
// The first line of input contains number of testcases , T.
// Then T lines follow, which contains 3 integers seperated by a space.
// Output Format
// For each testcase print 1 if the the numbers are consecutive , else print 0
// Sample Input
// 2
// 1 3 2
// 1 4 7
// Sample Output
// 1
// 0

#include <iostream>
#include <algorithm>
int threeConsecutive(int a, int b, int c){
  // Write your code here
    int arr[]={a ,b ,c};
    
    //sort(arr, arr + 3);  //sorting function
    if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1){
        
        return 1;
        
    } 
    return 0;
}


// Question 2: Write a function void reverseArray(int *a, int size) which takes two parameters i.e. an pointer to first element of array, an integer size.
// The function must reverse the array elements inside the array, Don't print the array elements as printing is done in main function.
// Input Format
// First line contains an integer t denoting the total number of elements.
// Second line contains t integer elements.
// Output Format
// Print the array elements separated by space after reversal.
// Sample Input
// 5
// 1 3 5 7 9
// Sample Output
// 9 7 5 3 1

void reverseArray(int *a, int size)
{
  int s = 0;
  int e = size - 1;
    while( s < e){
        int temp = a[s];
        a[s] = a[e];
        a[e] = temp;
        s++;
        e--;
    }
}