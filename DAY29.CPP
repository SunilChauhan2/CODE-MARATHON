/*Question 1: Given an expression only containing upper-case alphabets: A-Z, operators: /, * , +, - and characters: (,),{,},[,] used to mark start and end of parentheses, validate whether the parentheses are balanced or not.
Examples:
()    ==>  YES
)(    ==>  NO
(2+2) ==> YES
{3+(2+5)} ==> YES
{} ==> YES
(3*4+(6) ==>  NO
({2+5)} ==>  NO
Input Format:
A string with alphanumeric characters or one of the characters '{', '}', '(','),'[' or ']'.
Output Format:
For each test case print "YES" if the string has balanced parentheses, else print "NO"
Sample Input 1
()
Sample Output 1
YES
Explanation 1
The String is balanced
Sample Input 2
)(
Sample Output 2
NO
Explanation﻿ 2
The string is not balanced#include<iostream>*/

#include<stack>
using namespace std;
bool areBracketsBalanced(char exp[]) {
    stack<char> s;

  for (int i = 0; exp[i] != '\0'; i++) {
      char ch = exp[i];

      
      if (ch == '(' || ch == '{' || ch == '[') {
          s.push(ch);
      }

      else if (ch == ')' || ch == '}' || ch == ']') {
          
          if (s.empty()) {
              return false; 
          }
          char top = s.top();
          s.pop();
          if ((ch == ')' && top != '(') ||
              (ch == '}' && top != '{') ||
              (ch == ']' && top != '[')) {
              return false; 
          }
      }
  }

 
  return s.empty();
} 


/*Question 2: The Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree (BST) is defined as the deepest node from the root which lies in the path of both the nodes from the root.
So, given a binary search tree, find the Lowest Common Ancestor of two given nodes in it.
Complete the function lowestCommonAncestor() which takes the address of the root node of tree and two integer keys as parameters and return the lowest common ancestor of these two nodes (For empty tree return -1).
You can assume that both the given keys are present in the tree and are different from each other.
Input Format
First line contains an integer N, denoting the number of integers to follow in the serialized representation of the tree.
Second line contains N space separated integers, denoting the level order description of left and right child of nodes, where -1 signifies a NULL child.
Third line contains two integers k1 and k2 separated by space.
Output Format
Print the lowest common ancestor of given two nodes from the binary search tree.
Constraints
0 <= N <= 10^5
Sample Input
7
4 2 7 1 3 5 8
1 5
Sample Output
4
Explanation:

       4
      /  \
     2    7
    / \  / \
   1  3 5   8*/

struct Node {
        int data;
        Node *left, *right;
      };
    
    
    
   
   int lowestCommonAncestor(Node* root, int k1, int k2) {
    while (root != nullptr) {
       
        if (k1 < root->data && k2 < root->data) {
            root = root->left;
        }
        
        else if (k1 > root->data && k2 > root->data) {
            root = root->right;
        } else {
            
            return root->data;
        }
    }
    return -1; 
     
   }