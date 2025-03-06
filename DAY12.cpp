/**Question 1: Write a recursive function gcd that accepts two positive non-zero integer parameters i and j and returns the greatest common divisor of these numbers.
Sample Input
2 // Test Cases
30 18  // i j (testcase 1)
11 17  // i j (testcase 2)﻿
Sample Output
6
1**/

int gcd(int i, int j)
{
  if (j == 0)
        return i;
    return gcd(j, i % j);
}


/*Question 2: Given an array of integers and a positive integer R, rotate the array by shifting each element by R positions towards the left in a circular manner.
Input Format:
First line will contain the number of test cases. Each test case will contain 3 lines. 
First line of the test case will contain a number N = number of elements in the array. 
Next line will contain N space separated integers. 
The third line will contain an integer R = number of shifts in rotation. It is possible that R is greater than N. 
Output Format:
Print one line of output for each test case with the integers in the rotated array printed as space separated list.
NOTE: There should be no space after the last element.
Constraints:
1 <= T <= 100
1 <= N <= 10^5
0 <= arr[i] <= 10^5
1 <= R <= 10^6
Sample Input
3  // Test Cases
7
1 2 3 4 5 6 7
3
9
3 5 2 1 7 5 9 15 11
10
1
5
13
Sample Output
4 5 6 7 1 2 3
5 2 1 7 5 9 15 11 3
5*/


#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

// Function to rotate array to the left by R positions
void rotateLeft(vector<int>& arr, int R) {
    int N = arr.size();
    R = R % N; // Reduce R in case it's greater than N
    
    vector<int> rotatedArr(arr.begin() + R, arr.end());
    rotatedArr.insert(rotatedArr.end(), arr.begin(), arr.begin() + R);
    
    // Print the rotated array
    for (size_t i = 0; i < rotatedArr.size(); i++) {
        cout << rotatedArr[i];
        if (i != rotatedArr.size() - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, R;
        cin >> N;
        vector<int> arr(N);
        
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        cin >> R;
        
        rotateLeft(arr, R);
    }
    
    return 0;
}


