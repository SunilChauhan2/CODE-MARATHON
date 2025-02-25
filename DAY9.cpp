// Question 1: Given a number n, devise an algorithm to compute its square root.
// Input Format:
// First line will contain T=number of test case, next T lines will contains an integer n where n >=1.
// Output Format:
// For each test case, calculate and print the square root of n with 2 decimal places (Round to nearest numbers e.g. 4.472 to 4.47 & 3.157 to 3.16) in new lines.
// There should be no space after each element.
// Sample Input
// 6
// 36
// 16
// 9
// 20
// 1
// 11
// Sample Output
// 6.00
// 4.00
// 3.00
// 4.47
// 1.00
// 3.32

#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    for ( int i=0; i<n; i++){
        cout<<sqrt(arr[i])<<"\n";
    }

    return 0;
}

// Qustion 2: Given an array of n integers which is sorted but rotated by some number of times after sorting, and a integer k. Search the element k in this sorted rotated array efficiently. For example, suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Assume there are no duplicate elements in the array.
// Expected Time Complexity: O(log(N))
// Expected Space Complexity: O(1)
// Input Format
// First line of input will contain a number T = number of test cases. Each test case will contain 3 lines. The first line will contain an integer k to be searched. Second line will contain a number n = number of elements in the array. Next line will contain N space separated integers. 
// Complete the function int searchRotatedSortedArray() to search a value target in array a of size given, and if target found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Output Format
// Print the index of k in given array for each test case in new line if found and print -1 if k is not present in given array.
// Constraints
//   1 <= T <= 10
//  -1000 <= k <= 1000
//   1 <= n <= 10^5
//  -1000 <= arr[i] <= 1000
// Sample Input
// 2   // Test Cases
// 3               // k (testcase 1)
// 6               // n  
// 15 18 2 3 6 12  // arr[]
// 7               // k (testcase 2)
// 7               // n 
// 4 5 8 9 1 2 3   // arr[]
// Sample Output
// 3
// -1

int searchRotatedSortedArray(int arr[], int n, int k) {

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == k) return mid; 
        
        
        if (arr[left] <= arr[mid]) { 
            if (arr[left] <= k && k < arr[mid]) {
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        } else { 
            if (arr[mid] < k && k <= arr[right]) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
    }
    return -1; 
}
