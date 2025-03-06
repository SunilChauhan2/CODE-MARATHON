// Node* swapNodes(Node* head, int x, int y) {
//   if (x == y) return head; 

//     Node *nodeX = nullptr, *nodeY = nullptr;
//     Node *current = head;

    
//     while (current) {
//         if (current->data == x) nodeX = current;
//         if (current->data == y) nodeY = current;
//         current = current->next;
//     }

    
//     if (!nodeX || !nodeY) return head;

    
//     if (nodeX->next == nodeY) {
        
//         nodeX->next = nodeY->next;
//         nodeY->prev = nodeX->prev;

//         if (nodeX->next) nodeX->next->prev = nodeX;
//         if (nodeY->prev) nodeY->prev->next = nodeY;

//         nodeY->next = nodeX;
//         nodeX->prev = nodeY;
//     } else if (nodeY->next == nodeX) {
        
//         nodeY->next = nodeX->next;
//         nodeX->prev = nodeY->prev;

//         if (nodeY->next) nodeY->next->prev = nodeY;
//         if (nodeX->prev) nodeX->prev->next = nodeX;

//         nodeX->next = nodeY;
//         nodeY->prev = nodeX;
//     } else {
        
//         Node* tempPrevX = nodeX->prev;
//         Node* tempNextX = nodeX->next;
//         Node* tempPrevY = nodeY->prev;
//         Node* tempNextY = nodeY->next;

        
//         if (tempPrevX) tempPrevX->next = nodeY;
//         if (tempNextX) tempNextX->prev = nodeY;
//         if (tempPrevY) tempPrevY->next = nodeX;
//         if (tempNextY) tempNextY->prev = nodeX;

//         nodeY->prev = tempPrevX;
//         nodeY->next = tempNextX;
//         nodeX->prev = tempPrevY;
//         nodeX->next = tempNextY;
//     }

    
//     if (head == nodeX) head = nodeY;
//     else if (head == nodeY) head = nodeX;

//     return head;
// }

