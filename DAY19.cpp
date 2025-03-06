// void enqueue(int item) {
//     if ((rear + 1) % 4 == front) {
//         return;
//     }
//     if (front == -1) {
//         front = 0;
//         rear = 0;
//     } else {
//         rear = (rear + 1) % 4;
//     }
//     array[rear] = item;
// }
// int dequeue() {
//     if (front == -1) {
//         return -1;
//     }
//     int item = array[front];
//     if (front == rear) {
//         front = -1;
//         rear = -1;
//     } else {
//         front = (front + 1) % 4;
//     }
//     return item;
// }
#include <iostream>
using namespace std;

class Queue { 
    struct QNode { 
        int data; 
        QNode* next; 
        QNode(int d) { 
            data = d; 
            next = NULL; 
        } 
    }; 

    QNode *front, *rear; 

    public:
        
        Queue() {
            front = rear = NULL;  
        }

  
        void enQueue(int x) {
            QNode* new_node = new QNode(x);  
            if (rear == NULL) {  
                front = rear = new_node;  
                return;
            }
            rear->next = new_node;  
            rear = new_node;  
        }

        
        int deQueue() { 
            if (front == NULL) { 
                return -1;  
            }
            QNode* temp = front;  
            int data = front->data; 
            front = front->next; 
            if (front == NULL) { 
                rear = NULL;  
            }
            delete temp;  
            return data;  
        }
};


void processQueries(int queries[], int Q) {
    Queue q;
    for (int i = 0; i < Q; i++) {
        if (queries[i] == 1) {  
            i++;  
            q.enQueue(queries[i]);
        } else if (queries[i] == 2) {  
            int deletedElement = q.deQueue();
            cout << deletedElement << " ";
        }
    }
}

int num() {
    int Q;
    cin >> Q;  
    int queries[Q];
    for (int i = 0; i < Q; i++) {
        cin >> queries[i];  
    }

    processQueries(queries, Q);  
    return 0;
}