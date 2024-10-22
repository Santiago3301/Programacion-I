#include<stdio.h>
#include "pila.h"

int main(){
    Pila enteros;
    int opc;
    int n;

    init(&enteros);

    while(1){
        printf("Pila de enteros:\n");
        printf("ultimo elemento de la pila: %d", peek(enteros));
        printf("\n1. Ingresar un elemento: \n2. Eliminar el ultimo elemento\n");
        scanf("%d", &opc);

        switch(opc){
            case 1: printf("Elemento a ingresar: ");
                    scanf("%d", &n);
                    push(&enteros,n);
                    break;
            case 2: if(!isEmpty(enteros)){ pop(&enteros);}
                    else {printf("Pila vacia!\n");}
                    break;
            case 3: exit(1);
            default: break;
        }
    }
}
