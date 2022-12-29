#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * next;
} Node;

Node * newNode(int value) {
    Node * n = (Node*)malloc(sizeof(Node));
    n->next = NULL;
    n->value = value;
    return n;
}

typedef struct Stack {
    Node * top;
} Stack;

Stack * newStack() {
    Stack * s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
}

int isEmpty(Stack * s) {
    return s->top == NULL;
}

void push(Stack * s, int value) {
    Node * n = newNode(value);
    n->next = s->top;
    s->top = n;
}

int pop(Stack * s) {
    if(isEmpty(s))
        exit(2);
        
    Node * n = s->top;
    int value = n->value;
    s->top = s->top->next;
    free(n);
    return value;
}

void printStack(Stack * s) {
    Node * n = s->top;
    printf("[");
    while(n != NULL) {
        printf(" %d ", n->value);
        n = n->next;
    }
    printf("]\n");
} 

int main() {
    Stack * s = newStack();

    for(int i=0; i<6; i++) {
        push(s, rand()%10);
        printStack(s);
    }
    for(int i=0; i<6; i++) {
        printStack(s);
        pop(s);
    }

    return 0;
}