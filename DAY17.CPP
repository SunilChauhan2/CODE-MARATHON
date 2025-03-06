/*Question 1: Given a pointer to the head node of a doubly linked list and two keys, x and y respectively, swap these two nodes of the list (if these nodes exists in the list).
Note: All the linked list nodes contain distinct data.
Complete the function swapNodes(), which takes the head node of a doubly linked list along with x and y as a parameter, and returns the head of updated list after swapping the two nodes.
Input Format:
First line contains an integer denoting number of test cases.
Each test case has 4 lines. First line contains the number of elements in list, Second line contains the list elements separated by space.
Third and Fourth lines contains the node numbers to be swapped.
Output Format:
Print the integer data for each element of the modified linked list separated by space.
Constraints:
1 <= no. of testcases <= 10
0 <= no. of nodes <= 10^5
﻿﻿0 <= node data <= 10^6
0 <= x, y <= 10^6﻿
Sample Input
1             // test cases
6             // no. of nodes (TC-1)
1 2 3 4 5 6   // node's data
3             // x
5             // y
Sample Output
1 2 5 4 3 6*/

Node* swapNodes(Node* head, int x, int y) {
  if (x == y) return head; 

    Node *nodeX = nullptr, *nodeY = nullptr;
    Node *current = head;

    
    while (current) {
        if (current->data == x) nodeX = current;
        if (current->data == y) nodeY = current;
        current = current->next;
    }

    
    if (!nodeX || !nodeY) return head;

    
    if (nodeX->next == nodeY) {
        
        nodeX->next = nodeY->next;
        nodeY->prev = nodeX->prev;

        if (nodeX->next) nodeX->next->prev = nodeX;
        if (nodeY->prev) nodeY->prev->next = nodeY;

        nodeY->next = nodeX;
        nodeX->prev = nodeY;
    } else if (nodeY->next == nodeX) {
        
        nodeY->next = nodeX->next;
        nodeX->prev = nodeY->prev;

        if (nodeY->next) nodeY->next->prev = nodeY;
        if (nodeX->prev) nodeX->prev->next = nodeX;

        nodeX->next = nodeY;
        nodeY->prev = nodeX;
    } else {
        
        Node* tempPrevX = nodeX->prev;
        Node* tempNextX = nodeX->next;
        Node* tempPrevY = nodeY->prev;
        Node* tempNextY = nodeY->next;

        
        if (tempPrevX) tempPrevX->next = nodeY;
        if (tempNextX) tempNextX->prev = nodeY;
        if (tempPrevY) tempPrevY->next = nodeX;
        if (tempNextY) tempNextY->prev = nodeX;

        nodeY->prev = tempPrevX;
        nodeY->next = tempNextX;
        nodeX->prev = tempPrevY;
        nodeX->next = tempNextY;
    }

    
    if (head == nodeX) head = nodeY;
    else if (head == nodeY) head = nodeX;

    return head;
}

