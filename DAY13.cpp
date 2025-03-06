/*Question 1: Write a function mergeArrays which should merge two sorted arrays A and B to create one single sorted array.
If the number of elements initialized in A and B are m and n respectively, the resulting size of merged array after your code is executed should be m + n
Example :
Input :
A : [1 5 8]
B : [6 9]
Merged Array : [1 5 6 8 9]
Sample Input
4        // Size of 1st array
1 2 3 6  // Elements of 1st array
3        // Size of 2nd array
4 5 7    // Elements of 2nd array
Sample Output
1 2 3 4 5 6 7*/

int* mergeArrays(int a[], int b[], int asize, int bsize) {
    int* c = new int[asize + bsize];
    int i = 0, j = 0, k = 0;

    while (i < asize && j < bsize) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < asize) {
        c[k++] = a[i++];
    }

    while (j < bsize) {
        c[k++] = b[j++];
    }

    return c;
}

/*Question 2: Given a method called kthLargest that accepts an integer k and an array arr as its parameters and returns the element such that k elements have greater or equal value. If k = 0, return the largest element; if k = 1, return the second largest element, and so on.
For example, if the array passed contains the values {74, 85, 102, 99, 101, 56, 84} and the integer k passed is 2, your method should return 99 because there are two values at least as large as 99 (101 and 102).
Expected Time Complexity: O(N)
Assume that 0 <= k < length of array.
Input Format
First line contains the number of test cases i.e. T
Each test case T contains the integer K (In first line), the number of elements in array N (In 2nd line) and N array integers in the next line.
Output Format
Print the kth largest number from array.
Constraints
  0 <= K < N
  1 <= N <= 10^5
 -(10^9) <= arr[i] <= 10^9
Sample Input
1  // Test cases
1        // K
4        // Size of Array
8 5 6 3  // Elements of Array
Sample Output
6*/

int partition(int arr[], int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    
    swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] >= pivotValue) { 
            swap(arr[storeIndex], arr[i]);
            storeIndex++;
        }
    }
    
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}


int quickselect(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    
    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(arr, left, right, pivotIndex);

    
    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}


int kthLargest(int arr[], int n, int k) {
    return quickselect(arr, 0, n - 1, k);
}
