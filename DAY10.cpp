// Question 1: Given a sorted list of N integers, find all distinct pairs of integers in the list with sum equal to a given number K, with O(n log n) or O(n) time complexity.
// Complete the function below which takes the array and K as parameters and return the number of pairs if any and 0 otherwise.
// Input Format:
// First line of input will contain a positive integer T = number of test cases. Each test case will contain 2 lines.
// First line of each test case contains two integers - N and K. 
// Next line will contain N numbers separated by space in non-decreasing order.
// Constraints:
// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 10^5
// -(10^9) ≤ arr[i], K ≤ 10^9
// Output Format:
// For each test case, print number of distinct pairs whose sum will be equal to k. A pair must have two numbers at different indices. 
// Two pairs are different if at least one of the indices in them is uncommon. Indices - (2,3) and (3,2) are not distinct, but (2,3) and (2,4) are.
// Sample Input
// 3  // Test Cases
// 10 11  // N K (testcase 1)
// 1 2 3 4 5 6 7 8 9 10
// 5 10   // N K (testcase 2)
// 2 4 6 8 10
// 6 27   // N K (testcase 3)
// 12 15 20 22 34 36
// Sample Output
// 5
// 2
// 1

  int getPairsCount(int arr[], int n, int k) {
    int left = 0;
    int right = n - 1;
    int count = 0;
    while (left < right) {
        int pair_sum = arr[left] + arr[right];
        if (pair_sum == k) {
            count++;  
            left++;   
            right--;  
        } 
        else if (pair_sum < k) {
            left++;  
        } 
        else {
            right--;  
        }
    }
    
    return count;
}


// Question 2: Given a sorted list of integers with duplicates, find the count of a given number K in that list in O(log n) time.
// Input
// First line of input will contain a positive integer T = number of test cases. Each test case will contain 2 lines. 
// First line of each test case will contain two number N = number of elements in list and K separated by space. 
// Next line will contain N space separated integers.
// Constraints
//   1 <= N <= 10^5
//  -(10^9) <= arr[i], K <= (10^9)
// Output
// For each test case, print on a single line, the count of number K in this list.
// Sample Input
// 3  // Test Cases
// 10 5  // N K (testcase 1)
// 1 2 2 5 5 5 7 7 7 8
// 10 1  // N K (testcase 2)
// 1 1 1 1 1 1 1 2 2 3
// 20 2  // N K (testcase 3)
// 1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4
// Sample Output
// 3
// 7
// 5

#include <iostream>
using namespace std;
// Function to find the first occurrence of K
int findFirstOccurrence(int arr[], int N, int K) {
    int low = 0, high = N - 1;
    int firstIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < K) {
            low = mid + 1;
        } else if (arr[mid] > K) {
            high = mid - 1;
        } else {
            firstIndex = mid; // K found, continue searching in the left half
            high = mid - 1;
        }
    }
    return firstIndex;
}

// Function to find the last occurrence of K
int findLastOccurrence(int arr[], int N, int K) {
    int low = 0, high = N - 1;
    int lastIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < K) {
            low = mid + 1;
        } else if (arr[mid] > K) {
            high = mid - 1;
        } else {
            lastIndex = mid; // K found, continue searching in the right half
            low = mid + 1;
        }
    }
    return lastIndex;
}

// Function to count occurrences of K
int countOccurrences(int arr[], int N, int K) {
    int firstIndex = findFirstOccurrence(arr, N, K);
    if (firstIndex == -1) { // K is not found
        return 0;
    }
    int lastIndex = findLastOccurrence(arr, N, K);
    return lastIndex - firstIndex + 1;
}

int main() {
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int N, K;
        cin >> N >> K; // Read N and K
        int arr[100000]; // Declare an array with a maximum size of 100,000
        for (int i = 0; i < N; ++i) {
            cin >> arr[i]; // Read the sorted array
        }
        int result = countOccurrences(arr, N, K);
        cout << result << endl; // Output the result for each test case
    }
    return 0;
}