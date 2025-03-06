// void inorder(Node* root){
//  if (root == nullptr) {
//         return;
//     }
//     inorder(root->left);        
//     cout << root->data << " "; 
//     inorder(root->right); 
// }
// void preorder(Node* root){
//   if (root == nullptr) {
//         return;
//     }
//     cout << root->data << " ";  
//     preorder(root->left);        
//     preorder(root->right);  
// }
// void postorder(Node* root){
//   if (root == nullptr) {
//         return;
//     }
//     postorder(root->left);       
//     postorder(root->right);      
//     cout << root->data << " ";  
// }
// int findIndex(int in[], int start, int end, int value) {
//     for (int i = start; i <= end; i++) {
//         if (in[i] == value) {
//             return i;
//         }
//     }
//     return -1; 
// }


// Node* buildTreeUtil(int in[], int post[], int inStart, int inEnd, int& postIndex) {
   
//     if (inStart > inEnd) {
//         return nullptr;
//     }

   
//     int rootValue = post[postIndex];
//     Node* root = newNode(rootValue);
//     postIndex--; 


//     if (inStart == inEnd) {
//         return root;
//     }

    
//     int inIndex = findIndex(in, inStart, inEnd, rootValue);

   
//     root->right = buildTreeUtil(in, post, inIndex + 1, inEnd, postIndex);
//     root->left = buildTreeUtil(in, post, inStart, inIndex - 1, postIndex);

//     return root;
// }


// Node* buildTree(int in[], int post[], int N) {
//     int postIndex = N - 1; 
//     return buildTreeUtil(in, post, 0, N - 1, postIndex);
// }