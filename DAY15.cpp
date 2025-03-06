#include <iostream>

using namespace std;

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

int main() {
    int N;
    cin >> N; // Read the number of elements
    int* arr = new int[N]; // Dynamically allocate an array of size N

    // Read the elements of the array
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Call quickSort on the entire array
    quickSort(arr, 0, N - 1);

    // Print the sorted array
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}
void sortStrings(int n, string str[]) {
    
    sort(str, str + n);
    
    
    for (int i = 0; i < n; i++) {
        cout << str[i];
        if (i < n - 1) {
            cout << " "; 
        }
    }
     
}