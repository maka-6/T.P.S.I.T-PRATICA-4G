/*
 * Autore: Makaoui Youness
 * Classe: 4G
 * Luogo: Lab inf calini
 * Data: 20/09/2024
 * Descrizione:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20
#define MIN 0

int main(){

    int r, c;
    do {
        printf("\nBenvenuto\nInserisci n righe:\n->");
        scanf("%d",&r);
        printf("nInserisci n colonne:\n->");
        scanf("%d",&c);
    } while ( r > 20 || c > 20 || ( r < 0 || c < 0 ) );

    int rng;
    printf("\nInserisci range numeri:\n->");
    scanf("%d",&rng);

    int matrix[r][c];
    int i, j, k;

    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            matrix[i][j] = rand()% rng;
            printf("%3d ",matrix[i][j]);
        }
        printf("\n");
    }

    // ordinamento
    int n;
    int tmp;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            for (k = 0; k < c - j - 1; ++k) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    // Scambia gli elementi se non sono in ordine
                    tmp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = tmp;
                }
            }
        }
    }

    printf("\n\n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            printf("%3d ",matrix[i][j]);
        }
        printf("\n");
    }

}