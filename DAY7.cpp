// Question 1: Given a date with three elements date, month & year, your task is to print the next date of it.
// Input Format:
// The first line of input contains an integer T denoting the no of test cases. Each test case will contain a date in format '{date} {month} {year}'.
// Output Format:
// For each test case, print the next date in DD-MM-YYYY format on new lines.
// Sample Input
// 2
// 12 9 2016
// 28 2 2020
// Sample Output
// 13-09-2016
// 29-02-2020

#include <iostream>
#include <iomanip> // For std::setfill and std::setw
#include <vector> // For std::vector
using namespace std;

// // Function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// // Function to get the number of days in a month
int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// // Function to calculate the next date
void getNextDate(int day, int month, int year, int &nextDay, int &nextMonth, int &nextYear) {
    nextDay = day + 1;
    nextMonth = month;
    nextYear = year;
    
    if (nextDay > daysInMonth(month, year)) {
        nextDay = 1;
        nextMonth++;
        if (nextMonth > 12) {
            nextMonth = 1;
            nextYear++;
        }
    }
}

int main() {
    int T;
    
    cin >> T; // Read number of test cases

    // Creating vectors to store the input dates
    vector<int> days(T), months(T), years(T);
    
    // Read input dates
    for (int i = 0; i < T; i++) {
      
        cin >> days[i] >> months[i] >> years[i]; // Read the date
    }

    // Print next dates after all inputs are taken
   
    for (int i = 0; i < T; i++) {
        int nextDay, nextMonth, nextYear;
        getNextDate(days[i], months[i], years[i], nextDay, nextMonth, nextYear);
        cout << setfill('0') << setw(2) << nextDay << "-" 
             << setfill('0') << setw(2) << nextMonth << "-" 
             << nextYear << endl;
    }

    return 0;
}

// Qustion 2: Allocate a 1-D array of size nnn dynamically using malloc. The size n and its n elements are provided as input by the user. The program calculates the sum of the n elements and finds the average of these numbers. Finally, the dynamically allocated memory is freed to avoid memory leaks.
// In sample input first number is the size of array followed by these n numbers.
// sample input:
// 4 2 4 -2 1
// sample output:
// 2.50

int *dynamicMemoryAllocateArray(int n){
int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    return arr;
}
float findAverage(int *arr, int n){
float sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    float avg=sum/n;
    delete[] arr;
    return static_cast<int>(avg*100) / 100.0;
}