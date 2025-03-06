/*Question 1: A string is composing some words. These words are separated by some delimiter e.g. a space.
Given a string (with space as a delimiter between words), reverse the words in the string individually, not the whole string.
Complete the function revWordsString() which takes the string as parameter and reverse the individual words of string and print them.
Input Format:
The first line of input contains an integer T denoting the no of test cases. 
Each test cases contains one line, which contains a string.
Output Format:
For each test case, print the resultant string in new lines.
Sample Input
2
Code Quotient Loves Code
Hello Coders
Sample Output
edoC tneitouQ sevoL edoC
olleH sredoC*/
void reverseWord(string& str, int start, int end) {
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

void revWordsString(string str) {
    int n = str.length();
    int start = 0;

    
    for (int end = 0; end < n; end++) {
        
        if (str[end] == ' ' || end == n - 1) {
            
            if (end == n - 1) {
                end++;
            }
            
            reverseWord(str, start, end - 1);
            start = end + 1; 
        }
    }  
    cout << str ;
}

/*Question 2: Given a string, you need to test if it is palindrome or not. If the string is palindrome print “YES”, otherwise print “NO”.
Input Format
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains the string str. 
Function void isPalindrome(char *str) will take the string as parameter and print YES or NO according to palindrome or not.
Output Format
For each test case, print YES or NO in new lines.
Constraints
1 <= T <= 10
Given string consists of uppercase and lowercase English letters.
Sample Input
2
Coding
cooc
Sample Output
NO
YES*/

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