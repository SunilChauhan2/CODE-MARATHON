/*Question 1: Implement the circular queue using array representation.Complete the methods given in the editor.
Input Format:
First line of input contains number of test cases, T. The T test cases follow
First line of each test case contains an integer Q denoting the number of queries.
(a) 1 item  (a query of this type means insert 'item' into the queue)
(b) 2   (a query of this type means to delete element from queue and print the deleted element)
Then Q queries follow in following lines.
Output Format:
The output for each test case will be space separated integers having -2 if the queue is FULL, -1 if the queue is EMPTY else the element deleted from the queue.
Sample Input
1 // No. of test cases
6 // No. of operations
1 // 1-insert query
3 // node data
2 // 2-delete query
﻿1
4
1
﻿2
2
2
Sample Output
3 4 2
Explanation:
First query is insert 3, then delete will print 3, 3rd query is insert 4, then insert 2, 5th query is delete which prints 4, 6th query is delete will print 2.*/
void enqueue(int item) {
    if ((rear + 1) % 4 == front) {
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % 4;
    }
    array[rear] = item;
}
int dequeue() {
    if (front == -1) {
        return -1;
    }
    int item = array[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % 4;
    }
    return item;
}


/*Question 2: Implement the queue using linked list representation. Complete the methods given in the code editor.
Input Format
First line of input contains an integer Q denoting the number of queries.
(a) 1 item  (a query of this type means insert 'item' into the queue)
(b) 2   (a query of this type means to delete element from queue and print the deleted element)
The second line of each test case contains Q queries separated by space.
Output Format
The output for each test case will be space separated integers having -1 if the queue is empty else the element deleted from the queue.
Sample Input
8
1 3 2 1 4 1 2 2 1 6 2 2
Sample Output
3 4 2 6
Explanation:
First query is insert 3, then delete will print 3, 3rd query is insert 4, then insert 2, 5th query is delete which prints 4, 6th query is insert 6, then delete will print 2 and last query of delete will print 6.*/
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