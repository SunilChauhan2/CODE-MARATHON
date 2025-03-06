#include<iostream>
using namespace std;

// int loopInList(Node* head) {
//   if (head == nullptr) {
//         return 0; 
//     }
    
//     Node* slow = head;
//     Node* fast = head;
    
    
//     while (fast != nullptr && fast->next != nullptr) {
//         slow = slow->next;         
//         fast = fast->next->next;   
        
//         if (slow == fast) { 
            
//             int loop_count = 1;
//             Node* current = slow->next; 
//             while (current != slow) {
//                 loop_count++;
//                 current = current->next;
//             }
//             return loop_count; 
//         }
//     }
    
//     return 0; 
// }