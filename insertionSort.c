#include<stdio.h>

void insertionRec(int v[],int n){
    int lixo=-1;
    if(n<2){
        return ;
    }
    
    insertionRec(v,n-1);
    
    int aux = v[n-1];
    v[n-1]=lixo;
    int i = n-2;
    print(v,n);
    while(i>=0&&v[i]>aux){
        v[i+1]=v[i];
        v[i] = lixo;
        i--;
        print(v,n);
    }
    v[i+1]=aux;
    print(v,n);
}


void insertionIt(int v[],int N){
    int lixo=-1;

    int n=2;
    
    while(n<=N){
        int aux = v[n-1];
        v[n-1]=lixo;
        int i = n-2;
        print(v,n);
        while(i>=0&&v[i]>aux){
            v[i+1]=v[i];
            v[i] = lixo;
            i--;
            print(v,n);
        }
        v[i+1]=aux;
        print(v,n);
        n++;
    }
}