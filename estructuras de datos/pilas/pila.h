#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include<stdio.h>
#include<malloc.h>

//implementación de pila con listas enlazadas: no existe la fucnión isFull
typedef struct nodo{
    int dato;
    struct nodo *next;
}Nodo;

typedef struct{
    Nodo *top;
}Pila;

void init(Pila *p){
    p->top = NULL;
}

void push(Pila *p, int n){
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->dato = n;
    nuevoNodo->next = p->top;
    p->top = nuevoNodo;
}

int pop(Pila *p){
    if(!isEmpty(p)){
        Nodo *temp = p->top;
        int dato = temp->dato;
        p->top = p->top->next;
        free(temp);
        return dato;
    } else {
        printf("Pila vacia!\n");
        return -1;
    }

}

int peek(Pila p){ //copy
    if(!isEmpty(p))return(*p.top).dato;
    else printf("Pila vacia!\n");
    return -1;
}

int isEmpty(Pila p){
    return (p.top == NULL); //1 si esta empty, 0 si no esta empty
}



#endif // PILA_H_INCLUDED
