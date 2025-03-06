/*Question 1: A linked list is a collection of nodes stored in memory through pointers. These pointers may or may not be replicated, which might result in a loop of nodes.
Given a linked-list as input, check whether it contains a loop or not. If there is a loop return the number of nodes in the loop, otherwise return 0.
Complete the function loopInList() which takes the head node of a linked list as a parameter, and returns the number of nodes in loop if exists, 0 otherwise.
Input Format
First line contains the number of Test cases i.e. T.
Each test case contains the following:
  First line will contain N, denoting the number of nodes.
  Next N lines will contain the node's data.
  Last line will contain the starting position of loop in the list. If no loop exists, then this input will be -1.
Output Format
Print the number of nodes in the list involved in a loop.
Constraints
1 <= no. of testcases <= 10
0 <= no. of nodes <= 10^5
﻿0 <= node data <= 1000
Sample Input
1  // test cases
8    // no. of nodes (TC-1)
5 4 9 3 10 2 6 7
2    // This signifies the starting position of the loop (consider 0-based indexing)
Sample Output
6
Explanation
As 9 -> 3 -> 10 -> 2 -> 6 -> 7 -> 9 .... is the loop and 6 nodes are involved.*/

int loopInList(Node* head) {
  if (head == nullptr) {
        return 0; 
    }
    
    Node* slow = head;
    Node* fast = head;
    
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         
        fast = fast->next->next;   
        
        if (slow == fast) { 
            
            int loop_count = 1;
            Node* current = slow->next; 
            while (current != slow) {
                loop_count++;
                current = current->next;
            }
            return loop_count; 
        }
    }
    
    return 0; 
}