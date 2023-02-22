#include <stdio.h>

void bubbleRec(int v[],int n){
    if(n<2){
        return;
    }
    int aux;
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
        }
        print(v,n); //se for rodar, precisa criar essa função
    }
    bubbleRec(v,n-1);
    
}

void bubbleIte(int v[],int n){
    int aux;
    while(n>1){
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
            }
            print(v,n);
        }
        n--;
    }
    
}