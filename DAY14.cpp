#include <iostream>
#include <string>
using namespace std;

// void reverseWord(string& str, int start, int end) {
//     while (start < end) {
//         swap(str[start], str[end]);
//         start++;
//         end--;
//     }
// }

// void revWordsString(string str) {
//     int n = str.length();
//     int start = 0;

    
//     for (int end = 0; end < n; end++) {
        
//         if (str[end] == ' ' || end == n - 1) {
            
//             if (end == n - 1) {
//                 end++;
//             }
            
//             reverseWord(str, start, end - 1);
//             start = end + 1; 
//         }
//     }

   
//     cout << str ;
// }

// int main() {
//     string input;
//     cout << "Enter a string: ";
//     getline(cin, input); // Read the entire line of input
//     revWordsString(input); // Call the function to reverse each word
//     return 0;
// }
bool isPalindrome(string str) {
    int len = str.length();
    
    // Check characters from start and end moving towards the center
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false; // Not a palindrome
        }
    }
    
    return true;
}