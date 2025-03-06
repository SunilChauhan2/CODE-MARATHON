/*Question 1: Given a binary tree, print it in inorder, preorder and postorder fashion with recursion.
Input
The root node of binary tree is given to you, and you have to complete the function
void inorder(Node root), void preorder(Node root) & void postorder(Node root) 
to print the nodes of tree. (The function should use recursion).
Note: Do not read any input from stdin/console. Just complete the function provided. You can write more functions if required, but just above the given function.
Output
Print the nodes of tree separated by space by all three traversals in new lines.
Sample Input
6
1 2 3 4 5 6
Above input corresponds to below tree.
        1
       / \
      2    3
     / \  /
    4  5 6
Sample Output
4 2 5 1 6 3
1 2 4 5 3 6
4 5 2 6 3 1*/
void inorder(Node* root){
 if (root == nullptr) {
        return;
    }
    inorder(root->left);        
    cout << root->data << " "; 
    inorder(root->right); 
}
void preorder(Node* root){
  if (root == nullptr) {
        return;
    }
    cout << root->data << " ";  
    preorder(root->left);        
    preorder(root->right);  
}
void postorder(Node* root){
  if (root == nullptr) {
        return;
    }
    postorder(root->left);       
    postorder(root->right);      
    cout << root->data << " ";  
}
int findIndex(int in[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (in[i] == value) {
            return i;
        }
    }
    return -1; 
}


/*Question 2: Given two array representing the inorder and postorder traversal of a binary tree, construct the tree and return its root node.
Input
Two arrays for traversals and total number of nodes are given and you needs to write a function Node buildTree(int in[], int post[], int N), which accepts the inorder and postorder traversals of a binary tree and the number of nodes in the tree. The function returns the root node of the constructed tree.
Note: Do not read any input from stdin/console. Just complete the function provided. You can write more functions if required, but just above the given function.
Output
The nodes of tree will be printed separated by space using preorder traversal in new lines.
Sample Input
6 // Number of nodes
4 // inorder traversal
2 
5
1
6
﻿3
4 // Postorder traversal
5
2
6
3
1
Sample Output
1 2 4 5 3 6*/

// Given two array representing the inorder and postorder traversal of a binary tree, construct the tree and return its root node.

Input

Two arrays for traversals and total number of nodes are given and you needs to write a function Node buildTree(int in[], int post[], int N), which accepts the inorder and postorder traversals of a binary tree and the number of nodes in the tree. The function returns the root node of the constructed tree.
Note: Do not read any input from stdin/console. Just complete the function provided. You can write more functions if required, but just above the given function.

Output

The nodes of tree will be printed separated by space using preorder traversal in new lines.
Sample Input

6 // Number of nodes
4 // inorder traversal
2 
5
1
6
﻿3
4 // Postorder traversal
5
2
6
3
1
Sample Output

1 2 4 5 3 6
