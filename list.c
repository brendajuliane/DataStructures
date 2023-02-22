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

typedef struct List {
    Node * front;   
} List;

List * newList() {
    List * l = (List*)malloc(sizeof(List));
    l->front = NULL;
    return l;
}

int isEmpty(List * l) {
    return l->front == NULL;
}

void addRear(List * l, int value) {
    Node * no = newNode(value);
    Node * aux = l->front;

    if(isEmpty(l)) {
        l->front = no;
    } else {
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = no;
    }
}

int size(List * l) {
    int size = 0;
    if(isEmpty(l)) {
        return 0;
    } else {
        Node * no = l->front;
        while(no!=NULL) {
            size++;
            no = no->next;
        }            
        return size;
    }
}

Node * getNode(List * l, int position) {
    if(isEmpty(l)) {
        printf("Lista vazia\n");
        exit(2);
    }

Node * no = l->front;
    for(int i=0; i<position; i++) {
        if(no!=NULL) {
            no = no->next;
        } else {
            printf("Fora dos limites da lista");
            exit(3);
        }
    }
    return no;
}

int removeNext(Node * no) {
    Node * aux = no->next;
    if(aux==NULL) {
        printf("Fora dos limites\n");
        exit(3);
    }
    no->next = no->next->next;
    int value = aux->value;
    free(aux);
    return value;
}

void add(List * l, int position, int value) {
    Node * no = newNode(value);
    
    if(position==0) {
        no->next = l->front;
        l->front = no;
    } else {
        Node * aux = getNode(l, position-1);
        no->next = aux->next;
        aux->next = no;
    }
}

int pop(List * l, int position) {  
    if(position > 0) {
        Node * no = getNode(l, position-1);
        removeNext(no);
    } else {
        if(isEmpty(l)) {
            printf("Lista vazia/n");
            exit(2);
        }
        Node * aux = l->front;
        int value = l->front->value;
        l->front = l->front->next;
        free(aux);
        return value;
    }
}

void set(List * l, int position, int value) {
    Node * no = getNode(l, position);
    no->value = value;
}

void print(List *li){
    Node * aux = li->front;
    printf("[");
    while(aux!=NULL){
        printf("%d",aux->value);
        aux = aux->next;
        if(aux!=NULL){
            printf(",");
        }
    }
    printf("] (%d)\n",size(li));
}

int main() {
    List * l = newList();
    int position = 1;

    for(int i=0; i<6; i++) {
        addRear(l, rand()%20);
        print(l);
    }
    for(int i=0; i<6; i++) {
        print(l);
        pop(l, position);
    }

    return 0;
}
