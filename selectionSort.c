#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int v[],int n){
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d",v[i]);
        if(i<n-1){
            printf(",");
        }
    }
    printf("](%d)\n",n);
}

int max(int v[],int n){
    int m=0;
    for(int i=1;i<n;i++){
        if(v[i]>v[m]){
            m=i;
        }
    }
    return m;
}

void selectionRec(int v[],int n){
    int m,aux;
    if(n<2){
        return;
    }
    m = max(v,n);
    aux = v[m];
    v[m] = v[n-1];
    v[n-1]=aux;
    print(v,n);
    selectionRec(v,n-1);
}

void selectionIt(int v[],int n){
    int m,aux;
    while(n>1){
        m = max(v,n);
        aux = v[m];
        v[m] = v[n-1];
        v[n-1]=aux;
        n--;
    }
}