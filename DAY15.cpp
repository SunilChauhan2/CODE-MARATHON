/*Question 1: Given an array of N integers, sort them in ascending order using quick sort (a divide and conquer approach). It picks an element as pivot and partitions the given array around the picked pivot element recursively. Write the two functions quickSort() and partition(), in which the quickSort() choose an pivot using partition() function and calls itself on the two parts of array before and after the pivot element.
Input Format
First line contains the number of elements
Second line contains the elements of array separated by space.
Output Format
Print the elements of sorted array in ascending order.
Constraints
1 <= N <= 10^5
-(10^9) <= arr[i] <= 10^9
Sample Input
7
1 3 5 7 2 4 9
Sample Output
1 2 3 4 5 7 9*/

// Function to partition the array
int partition(int array[], int low, int high) {
    int pivot = array[high]; // Choosing the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (array[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(array[i], array[j]); // Swap
        }
    }
    swap(array[i + 1], array[high]); // Swap the pivot element with the element at i + 1
    return i + 1; // Return the partitioning index
}

// Function to perform quick sortay
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(array, low, high);

        // Recursively sort elements before and after partition
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

/*Question 2: Given a list of strings, sort them in lexicographical order i.e. dictionary order.
Input Format:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains the number of strings in it followed by the actual strings. 
Function void sortStrings(int n, string str[ ]) will take the number of strings and an array of strings as parameters and print them in sorted order.
Output Format:
For each test case, print the strings as space separated list in lexicographical order (without space after last string) in newlines.
Sample Input
2  // Test Cases
4 code quotient loves coders
5 hi cat ate my homework
Sample Output
code coders loves quotient
ate cat hi homework my*/
void sortStrings(int n, string str[]) {
    
    sort(str, str + n);
    
    
    for (int i = 0; i < n; i++) {
        cout << str[i];
        if (i < n - 1) {
            cout << " "; 
        }
    }
     
}