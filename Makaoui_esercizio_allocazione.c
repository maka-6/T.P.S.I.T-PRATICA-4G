/*
 * Autore: Makaoui Youness
 * Luogo: Aula 54
 * Classe: 4G
 * Data 01/10/2024
 * Description: Scrivere una funzione che crea un array di N elementi e la carica da input
 */

#include <stdio.h>
#include <stdlib.h>

int * alloc( int byte ){

    int * ptr;
    int i;
    for (i = 0; i < byte; ++i) {
        ptr = (int*) malloc(byte);
    }

    return ptr;
}

int main() {

    int byte;
    printf("\nInserisci N elementi:\n->");
    scanf("%d",&byte);
    int * ptr = alloc(byte);
    int i;
    for (i = 0; i < byte; ++i) {
        printf("%d ",*(ptr+1));
    }
    main();
    free(ptr);
}