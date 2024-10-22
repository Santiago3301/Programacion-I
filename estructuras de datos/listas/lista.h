//TDA lista de enteros

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct nodo{
    int vipd;
    struct nodo *next;
};

typedef struct nodo Nodo;

typedef struct{
    Nodo *acc; //acceso a la lista
    Nodo *cur; //cursor de la lista
    Nodo *aux; //cursor auxiliar
}ListaInt;

//-Operaciones sobre cursor

void reset_l(ListaInt *l){
    l->cur = l->acc;
    l->aux = l->acc;
}

int isOos_l(ListaInt l){
    if(l.cur == NULL) return 1;
    return 0;
}

int forward_l(ListaInt *l){
    if(!isEmpty_l(*l) && !isOos_l(*l)){ //verificar lista no vacia y que cur no apunta a null
      if(l->cur != l->aux){ //aux apunta al anterior del cursor
        l->aux = l->aux->next; //aux avanza
      }
      l->cur = l->cur->next; //cursor avanza
      return 1; //operacion excitante
    }
    return 0; //error: operacion no excitante
}

//-Operaciones sobre lista

void init_l(ListaInt *l){
    l->acc = NULL;
    l->aux = NULL;
    l->cur = NULL;
}

int isEmpty_l(ListaInt l){
    if(l.acc == NULL) return 1;
    return 0;
}

int copy_l(ListaInt l){ //peek/check (ver el valor guardado en el cursor)
    return l.cur->vipd;
}

int insert_l(ListaInt *l, int x){
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if(nuevo == NULL) return 0; //Si no hay espacio termina
    nuevo->vipd = x;
     if(l->cur == l->acc){ //acc y cur apuntan a null
        l->acc = nuevo; //acc apunta al nuevo primer elemento
        nuevo->next = l->cur; //el nuevo elemento apunta al antiguo primer elemento
        l->cur = nuevo; //cursor ahora apunta al nuevo elemento
        l->aux = nuevo;
     } else { //cualquier otro caso: cursor apunta al aux.next
        nuevo->next = l->cur;
        l->aux->next = nuevo;
        l->cur = nuevo;
     }
     return 1;
}

void supress_l(ListaInt *l){ //pop (eliminar un elemento de la lista)
    if(l->acc == l->cur){
        l->acc = l->cur->next;
        l->aux = l->acc;
        free(l->cur);
        l->cur = l->aux;
    } else {
        l->aux->next = l->cur->next;
        free(l->cur);
        l->cur = l->aux->next;
    }
}

#endif // LISTA_H_INCLUDED
