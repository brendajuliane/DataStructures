#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * next;
} Node;

Node * newNode(int value) {
    Node * n = (Node*)malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    return n;
}

typedef struct Queue {
    Node * front;
    Node * rear;
} Queue;

Queue * newQueue() {
    Queue * q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue * q) {
    return q->front == NULL;
}

void enqueue(Queue * q, int value) {
    Node * no = newNode(value);
    if(isEmpty(q)) {
        q->front = no;
        q->rear = no;
    } else {
        q->rear->next = no;
        q->rear = no;
    }
}

int dequeue(Queue * q) {
    if(isEmpty(q)) 
        exit(2);
    
    Node * n = q->front;
    int value = n->value;
    if(q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
    }
    free(n);
    return value;
}

int size(Queue * q) {
    int size = 0;
    Node * n = q->front;

    while(n != NULL) {
        size++;
        n = n->next;
    }
    return size;
}

void printQueue(Queue * q) {  
    Node * n = q->front;

    printf("[");
    while(n != NULL) {
        printf(" %d ", n->value);
        n = n->next;
    }
    printf("] size: %d\n", size(q));
}

int main() {
    Queue * q = newQueue();

    for(int i=0; i<6; i++) {
        enqueue(q, rand()%20);
        printQueue(q);
    }
    for(int i=0; i<6; i++) {
        printQueue(q);
        dequeue(q);
    }

    return 0;
}