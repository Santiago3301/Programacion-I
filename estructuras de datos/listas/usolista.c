//lista de enteros

#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include "lista.h"

int i = 0;

/*void insert_n_ints(ListaInt *ls, int n){
    int dato;

    int n;
    printf("cuantos enteros queres meter: ");
    scanf("%d", &n);
    reset_l(&ls);
    for(i=0; i<n; i++){
        printf("\nentero n%d: ", i+1);
        scanf("%d", &dato);
        insert_l(&ls, dato);
        forward_l(&ls);
    }

    printListStatus(ls);
    printf("\n");
} */

void printListStatus(ListaInt ls){
    printf("\nacc: %d, %p\n", ls.acc, ls.acc);
    printf("cur: %d, %p\n", ls.cur, ls.cur);
    //printf("valor apuntado por cur: %d\n", ls.cur->vipd);
    printf("aux: %d, %p\n", ls.aux, ls.aux);
    printf("isEmpty_l: %d\n", isEmpty_l(ls));
    printf("isOos_l: %d\n", isOos_l(ls));
}

Nodo* buscarInt(ListaInt l, int x){
    printf("\nIngresa el valor a buscar en la lista: ");
    scanf("%d", &x);
    //busqueda
    int cont = 0, found = 0;
    reset_l(&l);
    while(!isOos_l(l)){
        if(l.cur->vipd == x){
            found = 1;
            break;
        }
    forward_l(&l);
    cont++;
    }
    if(!found){
        printf("\nElemento no encontrado");
    } else printf("\nElemento x == %d encontrado tras %d pasos", x, cont);
    return l.cur;
}


int main(){
    ListaInt lista;
    init_l(&lista);

    int opc, x;

    do{
        system("cls");
        //menu
        printf("-----------Muy buenardas!-----------\n");
        printf("1. Aniadir un elemento\n");
        printf("2. Mostrar lista\n");
        printf("3. Buscar un elemento\n");
        printf("4. Modificar un elemento\n");
        printf("5. Eliminar un elemento\n");
        printf("6. Avanzar con el cursor\n");
        printf("7. Ver valor apuntado por el cursor\n");
        printf("8. printListStatus\n");
        printf("0. Salir\n");

        printf("\nOpcion: ");
        scanf("%d", &opc);

        switch(opc){
            case 1: printf("\nIngresa el valor que queres aniadir: ");
                    //printListStatus(lista);
                    scanf("%d", &x);
                    insert_l(&lista, x);
                    forward_l(&lista);
                    printf("\nElemento aniadido!\n");
                    printf("\n");
                    break;

            case 2: if(!isEmpty_l(lista)){
                    reset_l(&lista);
                    printf("\nLista de enteros: \n");
                    while(!isOos_l(lista)){
                        printf("%d", lista.cur->vipd);
                        //printListStatus(lista);
                        if(lista.cur->next != NULL) printf(", ");
                        forward_l(&lista);
                    }
                    } else printf("\nLista vacia!");
                    break;

            case 3: if(!isEmpty_l(lista)) buscarInt(lista, x);
                    else printf("\nLista vacia!");
                    break;

            case 4: if(!isEmpty_l(lista)){
                        lista.cur = buscarInt(lista, x);
                        x = 0;
                        printf("\nIngresa el nuevo valor: ");
                        scanf("%d", &x);
                        printListStatus(lista);
                        lista.cur->vipd = x;
                    }else printf("\nLista vacia!");
                    break;

            case 8: printListStatus(lista);
                    break;

            case 0: break;
            default: printf("\nEsa opcion no esta programada aun.");
                     break;
        }
        printf("\nPresiona ESC para salir");
    }while(getch() != 27);
    // **eliminar lista al final**
    free(&lista);
    printf("\n\nsexo");
    return 0;
}
