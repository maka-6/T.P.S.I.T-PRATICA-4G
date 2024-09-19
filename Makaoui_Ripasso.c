/*
 * Autore: Makaoui Youness
 * Classe: 4G
 * Luogo: Lab 53 bis
 * Data: 19/09/2024
 * Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 1

int main(){

    srand(time(NULL));

    int m;
    do {
        printf("\nBenvenuto\nInserisci un numero max 10:\n-> ");
        scanf("%d", &m);
    } while ( m > 10 );

    int matrix[m][m];
    int i, j;
    // produttoria diagonale secondaria
    int prod;
    printf("\n");
    for (i = 0; i < m; ++i) {
        for (j = 0; j < m; ++j) {
            matrix[i][j] = rand()% MAX + MIN;
            printf("%4d",matrix[i][j]);
        }
        printf("\n");
    }

    prod = 1;
    i = 0;
    for (j = m-1; j >= 0; --j) {
        prod *= matrix[i][j];
        i++;
    }
    printf("\nProduttoria diagonale secondaria: %d", prod);

    for (i = 1; i < m; ++i) {
        for (j = 0; j < i; ++j) {
            if ( matrix[i][j] % 2 == 0 )
                printf("\n pari: %d",matrix[i][j]);
        }

    }
    printf("\n");

    for (i = 0; i < m; ++i) {
        if ( matrix[i][i] % 3 == 0 )
            printf("\nFizz");
        if ( matrix[i][i] % 5 == 0 )
            printf(" Buzz");
    }
}