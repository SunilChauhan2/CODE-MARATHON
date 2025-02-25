// Question 1: In C you can pass parameters to a function either by value or by reference. Changes made to variables passed by reference persists after the function. Hence you can pass any number of parameters as reference, which you want to return from function.
// Complete the function given below which takes several parameters and store the minimum, maximum & sum of array in passed pointer variables, so that it can be used in main function.
// Input Format
// First line contains an integer t denoting the total number of elements.
// Second line contains t integer elements.
// Output Format
// Print the minimum, maximum and sum of array elements separated by space.
// Sample Input
// 5
// 1 3 5 7 9
// Sample Output
// 1 9 25

void multiReturnArray(int *a, int size, int *min, int *max, int *sum)
{
   
    *min = a[0];
    *max = a[0];
    *sum = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] < *min) {
            *min = a[i];
        }
        if (a[i] > *max) {
            *max = a[i];
        }
        *sum += a[i];
    }

}


// Qustion 2:Write is a program to perform dynamic memory allocation (DMA) through a separate function and multiply two matrices using a separate function as well. The program takes the size of both matrices and their elements as input, calculates the resultant matrix, and displays it in matrix format. In sample input first line size of first array followed by its element in next line. third line size of second array followed by its elements in next line.
// Sample input:
// 2 3
// 1 2 3 4 5 6
// 3 2
// 7 8 9 10 11 12
// Sample output:
// 58 64
// 139 154

int** allocateMatrix(int rows, int cols) {
int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}


void multiplyMatrices(int **mat1, int **mat2, int **result, int r1, int c1, int c2) {
    
        // Multiply matrices
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    } 


void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    // Free memory for the matrix
    delete[] matrix;
}
