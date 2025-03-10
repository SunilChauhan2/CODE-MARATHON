/*Question 1: Given a binary tree print all paths from root node to leaf nodes with their respective lengths and total number of paths in it.
The root node of binary tree is given to you. A path from root to leaf in a tree is a sequence of adjacent nodes from root to any leaf node.
Do not write the whole program, just complete the function void printAllPaths(Node root) which takes the address of the root as a parameter and print all details as shown below.
Note: If the tree is empty, do not print anything.
Input Format
First line contains an integer N, denoting the number of integers to follow in the serialized representation of the tree.
Second line contains N space separated integers, denoting the level order description of left and right child of nodes, where -1 signifies a NULL child.
Output
For each test case, print the paths with their length and total paths in new lines.
Constraints
0 <= N <= 10^5
0 <= node data <= 1000
Sample Input

        1
       / \
      2    3
     / \  /
    4  5 6
Sample Output
1 2 4 2
1 2 5 2
1 3 6 2
3
Explanation:
First path is from 1 to 4 having 2 edges, so 1 2 4 is path and 2 is length of it. 
Similarly for other two leaf nodes. And at last line total number of paths are printed.*/

void printPathsUtil(Node* root, int path[], int pathLen, int& totalPaths) {
    if (root == nullptr) {
        return;
    }

    
    path[pathLen] = root->data;
    pathLen++;

    
    if (root->left == nullptr && root->right == nullptr) {
    
        for (int i = 0; i < pathLen; i++) {
            std::cout << path[i] << " ";
        }
        std::cout << pathLen - 1 << std::endl; 
        totalPaths++;
    } else {
        
        printPathsUtil(root->left, path, pathLen, totalPaths);
        printPathsUtil(root->right, path, pathLen, totalPaths);
    }
}

void printAllPaths(Node* root) {
    if (root == nullptr) {
        return;
    }

    int path[1000]; 
    int totalPaths = 0;

    printPathsUtil(root, path, 0, totalPaths);
    
    
    std::cout << totalPaths << std::endl;
}


/*Question 2:Given a binary search tree and a number k, print the kth smallest number in tree.
Input
The root node of binary search tree is given to you. Do not write the whole program, just complete the function int kSmallest(Node root, int k) which takes the address of the root node of tree and an integer k as parameters and return the kth smallest number from tree.
Note: Do not read any input from stdin/console. Just complete the function provided. You can write more functions if required, but just above the given function.
Output
Print the kth smallest number from the binary search tree.
Sample Input

        4
       / \
      2   7
     / \  / \
    1  3 5  8
k = 4
k = 6
Sample Output
4
7*/

void inorder(Node* root, int k , int& count , int & result){
    if ( root == nullptr || count >=k){
        return;
    }
    inorder(root-> left, k ,count , result);
    count ++;
    if (count == k){
        result = root -> data;
        return;
    }
    inorder (root -> right, k ,count, result);
}
int kSmallest(Node* root, int k) {
  int result = 0;
    int count = 0;
    inorder(root, k , count , result);
    return result;
  
}