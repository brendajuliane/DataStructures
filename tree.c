#include <stdio.h>
#include <stdlib.h>

typedef struct ListaSeq {
    int *v;
    int top,max;
} ListaSeq;

ListaSeq * newLista(int max){
    ListaSeq * aux = (ListaSeq *)malloc(sizeof(ListaSeq));
    aux->top = 0;
    aux->max = max;
    aux->v = (int *)malloc(sizeof(int)*max);
    return aux;
}

void printLSeq(ListaSeq *l){
    printf("[");
    for(int i=0;i<l->top;i++){
        printf("%d",l->v[i]);
        if(i<l->top-1){
            printf(",");
        }
    }
    printf("]\n");
}

void addLSeq(ListaSeq *l, int valor){
    if(l->top==l->max){
        printf("Lista cheia\n");
        exit(0);
    }
    l->v[l->top++]=valor;
}


// binary tree implementation
typedef struct Node {
    int value;
    struct Node * right;
    struct Node * left;
} Node;


Node * newNode(int value) {
   Node * n = (Node*)malloc(sizeof(Node));
   n->value = value;
   n->right = NULL;
   n->left = NULL;
   return n;
}


typedef struct Tree {
    Node * raiz;
} Tree;


Tree * newTree() {
    Tree * t = (Tree*)malloc(sizeof(Tree));
    t->raiz = NULL;
    return t;
}


void addNode(Node * Node, int value) {
    if(value > Node->value) {
        if(Node->right == NULL) 
            Node->right = newNode(value);
        else 
            addNode(Node->right, value);
    } else {
        if(Node->left == NULL) 
            Node->left = newNode(value);
        else 
            addNode(Node->left, value);
    }
}

void addNodeTree(Tree * t, int value) {
    if(t->raiz == NULL) {
        t->raiz = newNode(value);
    } else {
        addNode(t->raiz, value);
    }
}

void printTree(Node * Node) {
    if(Node==NULL) {
        return;
    } 
    printTree(Node->left);
    printf("%d ", Node->value);
    printTree(Node->right);
}


//treeSorts com lista sequencial e lista ligada
void TreeToVector(Node * Node, ListaSeq * l) {
    if(Node==NULL) {
        return;
    }
    TreeToVector(Node->left, l);
    addLSeq(l, Node->value);
    TreeToVector(Node->right, l);
}

void TreeSortSeq(ListaSeq * l) {
    Tree * t = newTree();
    for(int i=0; i<l->top; i++) {
        addNodeTree(t, l->v[i]);
    }
    l->top = 0;
    TreeToVector(t->raiz, l);
    free(t);
}

int sizeTree(Node * Node) {
    if (Node==NULL) {
        return 0;
    }
    int left = sizeTree(Node->left);
    int right = sizeTree(Node->right);
    return 1+left+right;
}

int main() {
    Tree * t = newTree();
    ListaSeq * l = newLista(10);
    
    for(int i=0; i<10; i++) {
        addNodeTree(t, rand()%25);
        addLSeq(l, rand()%30);
    }
    
    printf("Tree: \n");
    printTree(t->raiz);
    
    printf("\n\nLista sequencial: \n");
    printLSeq(l);
    TreeSortSeq(l);
    printf("\nLista sequencial ordenada: \n");
    printLSeq(l);
}
