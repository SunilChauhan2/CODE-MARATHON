/*Question 1: Given a text file in current directory, print its contents backwards from last word of last line back to the first word of first line.
Input
You have been provided a text file name in input. 
Output
Print the contents of file in backward manner.
Sample Input
file1.txt
Let the contents of file1.txt are as below:
This is line one
Hello welcome to programming
Code Quotient - Get better at coding
This is last line of file
Sample Output
file of line last is This
coding at better Get - Quotient Code
programming to welcome Hello
one line is This*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include <fstream>
#include <vector>
#include <string>

// Include headers as needed

using namespace std;

int main()
{
    string filePath;
    
    cin >> filePath;

    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file!" <<endl;
        return 1;
    }

    vector<string> oddLines;
    vector<string> evenLines;
    string line;
    int lineNumber = 1;

    while (getline(file, line)) {
        if (lineNumber % 2 != 0) {
            oddLines.push_back(line); 
        } else { 
            evenLines.push_back(line); 
        }
        lineNumber++;
    }

    file.close();

    
    for (const auto& oddLine : oddLines) {
        cout << oddLine <<endl;
    }

    for (const auto& evenLine : evenLines) {
        cout << evenLine << endl;
    }

    return 0;
}
