/*
 * Autore: Makaoui Youness
 * Luogo: 
 * Classe: 4G
 * Data 06/10/2024
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funzione per caricare i numeri dal file e aggiungere numeri casuali
int LoadNum( FILE *pfile, float **num ){
    int i = 0;
    int capacita = 10;

    // Allochiamo un array dinamico inizialmente con una capacità di 10 elementi
    *num = (float *)malloc(capacita * sizeof(float));
    if (*num == NULL) {
        printf("Errore di allocazione della memoria.\n");
        return -1;
    }

    // Leggiamo i numeri dal file
    while (fscanf(pfile, "%f", num[i]) == 1) {
        i++;
        // Se l'array è pieno, lo ridimensioniamo
        if (i >= capacita) {
            capacita *= 2;
            *num = (float *)realloc(*num, capacita * sizeof(float));
            if (*num == NULL) {
                printf("Errore durante il realloc.\n");
                return -1;
            }
        }
    }

    fclose(pfile);

    // Aggiungiamo numeri casuali
    int n = rand() % 50;  // Numero di numeri casuali da aggiungere (tra 0 e 50)
    *num = (float *)realloc(*num, (i + n) * sizeof(float)); // Ridimensioniamo per i nuovi numeri
    if (*num == NULL) {
        printf("Errore durante il realloc.\n");
        return -1;
    }

    // Aggiungiamo i numeri casuali generati da rand()
    for (int j = 0; j < n; ++j, i++) {
        (*num)[i] = (float)rand() / RAND_MAX * 100.0;  // Numeri casuali tra 0 e 100
    }

    return i;  // Ritorniamo la dimensione totale dell'array
}


// Funzione per ordinare i numeri (ordinamento a bolle)
void SortNum(float *num, int size) {
    int i, j;
    float tmp;
    for (i = 0; i < size - 1; ++i) {
        for (j = i + 1; j < size; ++j) {
            if (num[i] > num[j]) {
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Apriamo il file per la lettura
    FILE *pFile = fopen("NumeriReali.txt", "r");
    if (pFile == NULL) {
        printf("Impossibile accedere al file. Riprova.\n");
        return 0;
    }

    // Variabile per l'array di numeri
    float *Num;

    // Carichiamo i numeri dal file e aggiungiamo numeri casuali
    int numSize = LoadNum(pFile, &Num);
    if (numSize == -1) {
        return 1;  // Errore durante il caricamento
    }

    // Ordiniamo i numeri
    SortNum(Num, numSize);

    // Stampiamo i numeri ordinati
    printf("Numeri ordinati:\n");
    for (int i = 0; i < numSize; i++) {
        printf("%f\n", Num[i]);
    }

    // Deallochiamo la memoria
    free(Num);
    return 0;
}